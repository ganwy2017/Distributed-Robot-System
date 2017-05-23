#!/usr/bin/env python

import math
import numpy as np
import operator
import pygame

from scripts.grid import Grid
from scripts.motors import Motors


def action2drive(action):
    if action == "Reverse":
        return [-255, -255]
    elif action == "Left":
        return [-255, 255]
    elif action == "Right":
        return [255, -255]
    elif action == "Forward":
        return [255, 255]
    else:
        return [0, 0]


class Buggy(object):

    def __init__(self, nb=0, col=(0, 0, 0), pos=(0, 0), angle=0, res=20,
                 sonars=None, encoders=None, servos=None, cameras=None, gyroscopes=None):
        self.nb = nb                                              
        self.col = col
        self.pos = pos                                           
        self.angle = angle
        self.mode = "Manual"
        self.modes = ["Manual", "Roam"]
        self.grid = Grid(100, res)
        self.servo_angles = [0, 0]
        self.sonars = sonars
        self.servos = servos
        self.cameras = cameras
        self.encoders = encoders
        self.gyroscopes = gyroscopes
        self.current_camera = 0
        self.motors = Motors(nb)
        self.encoder_last = [encoder.read() for encoder in encoders]    # For removing offset
        self.body = ((-6, -9), (6, -9), (6, 9), (-6, 9)) 
    
    def update(self, drive_cmd, servo_cmd):
        action = self._check_for_override()
        if action != "None":
            drive_cmd = action2drive(action)
        self.motors.drive(drive_cmd)                                    # Publish motor control (drive)
        disp = self._get_displacement()                                 # Calculate total displacement
        x = disp * math.sin(-self.angle)                                # Calculate displacement in x
        y = disp * math.cos(-self.angle)                                # Calculate displacement in y
        self.pos = [self.pos[0] + x, self.pos[1] + y]                   # Calculate the position of the buggy
        self._update_sonars()
        self._update_servos(servo_cmd)                                  # Update the servo angles
        self._update_gyroscopes()
        self.grid.update(self.sonars)                                   # Update the grid

    def draw(self, display, pos, scale):
        outline = self._transform(pos, scale)
        pygame.draw.polygon(display, self.col, outline)
        self._draw_sonar(display, pos, scale)

    def get_frame(self):
        if self.cameras:
            return self.cameras[self.current_camera].get_frame()
        else:
            return False

    def _check_for_override(self):
        for sonar in self.sonars:
            if sonar.action != "None":
                if sonar.data < sonar.min_dist and sonar.data != 0:
                    return sonar.action
        return "None"

    def _update_gyroscopes(self):
        for gyroscope in self.gyroscopes:
            data = gyroscope.get_data()
            for ch in ['(', ' ', ')']:
                if ch in data:
                    data = data.replace(ch, '')
            data = data.split(',')
            self.angle = -float(data[gyroscope.axis])

    def _update_sonars(self):
        for sonar in self.sonars:
            sonar.update(self.pos, self.angle)                  # Update all sonar

    def _update_servos(self, servo_change):
        for i, angle in enumerate(servo_change):
            if angle == "reset":
                servo_change[i] = -self.servo_angles[i]
        self.servo_angles = map(operator.add, self.servo_angles, servo_change)
        for servo in self.servos:
            if self.servo_angles[servo.axis] > servo.max:
                self.servo_angles[servo.axis] = servo.max
            elif self.servo_angles[servo.axis] < servo.min:
                self.servo_angles[servo.axis] = servo.min
            servo.move(self.servo_angles[servo.axis])                           # Update all servos

    def _draw_sonar(self, display, pos, scale):
        for sonar in self.sonars:
            sonar.update(self.pos, self.angle)                            
            sonar.draw(display, pos, self.angle, scale)   

    def _transform(self, pos, scale):
        outline = []                                                            # Initialise outline of buggy
        for point in self.body:                                                 # For every point in the outline
            if point[0]:                                                        # If point != 0
                angle = math.atan(-float(point[1]) / float(point[0])) - self.angle   # Calculate angle
            else:                                                               # Else avoid divide by zero
                angle = 90.0 - self.angle                                       # atan(x/0) = 90
            if point[0] < 0:                                                    # If x coord of point is less than zero
                angle += math.pi                                                # Flip by 180 degrees
            l = (point[0] ** 2 + point[1] ** 2) ** 0.5                          # Hypotenuse of point
            x = round(-l * math.cos(angle), 0) * scale + pos[0]                  # Rotate and shift x
            y = round(-l * math.sin(angle), 0) * scale + pos[1]                 # -l because of pixel coordinate system
            outline.append([x, y])                                              # Append coord to outline
        return outline                                                              

    def _get_displacement(self):
        twisting = self.motors.left_dir != self.motors.right_dir
        encoder_data = [float(encoder.read()) for encoder in self.encoders]
        encoder_step = [float(encoder.dist_per_tick) for encoder in self.encoders]
        if twisting: 
            self.encoder_last = encoder_data
            disp = 0
        else:
            disp = np.array(encoder_data) - np.array(self.encoder_last)         # Number of clicks since last checked
            disp *= np.array(encoder_step)                                      # Multiply by distance travelled per click
            disp = np.mean(disp)                                                # Take mean encoder value
            self.encoder_last = encoder_data
        return disp
