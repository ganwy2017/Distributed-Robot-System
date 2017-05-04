#!/usr/bin/env python

import pygame
import numpy as np
import math

from scripts.motors import Motors
from scripts.grid import Grid


class Buggy(object):

    def __init__(self, nb=0, col=(0, 0, 0), pos=(0, 0), angle=0, sonars=None, encoders=None, res=20):
        self.nb = nb                                              
        self.col = col
        self.pos = pos                                           
        self.angle = angle
        self.grid = Grid(40, res)
        self.sonars = sonars
        self.encoders = encoders
        self.motors = Motors(nb)
        self.encoder_last = [encoder.read() for encoder in encoders]    # For removing offset
        self.body = ((-6, -9), (6, -9), (6, 9), (-6, 9)) 
    
    # Update buggy position and angle
    def update(self):
        disp = self._get_displacement()
        # self.angle = gyro.read()
        x = disp * math.sin(-self.angle)
        y = disp * math.cos(-self.angle)
        self.pos = [self.pos[0] + x, self.pos[1] + y]
        for sonar in self.sonars: 
            sonar.update(self.pos, self.angle)  
        self.grid.update(self.sonars)

        # Publish motor drive values
    def drive(self, left, right):
        self.motors.drive(left, right)

    # Draw buggy given display, position on screen and scale
    def draw(self, display, pos, scale):
        outline = self._transform(pos, scale)                    
        pygame.draw.polygon(display, self.col, outline)        
        self._draw_sonar(display, pos, scale)                     

    # Call draw for every sonar device
    def _draw_sonar(self, display, pos, scale):
        for sonar in self.sonars:
            sonar.update(self.pos, self.angle)                            
            sonar.draw(display, pos, self.angle, scale)   

    # Transform buggy body given position (on screen) and scale
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
            x = round(l * math.cos(angle), 0) * scale + pos[0]                  # Rotate and shift x
            y = round(-l * math.sin(angle), 0) * scale + pos[1]                 # -l because of pixel coordinate system
            outline.append([x, y])                                              # Append coord to outline
        return outline                                                              

    # Get displacement since this was last called
    def _get_displacement(self):
        twisting = self.motors.left_dir != self.motors.right_dir
        encoder_data = [float(encoder.read()) for encoder in self.encoders]
        encoder_step = [float(encoder.step) for encoder in self.encoders]
        if twisting: 
            self.encoder_last = encoder_data
            disp = 0
        else:
            disp = np.array(encoder_data) - np.array(self.encoder_last)         # Number of clicks since last checked
            disp *= np.array(encoder_step)                                      # Multiply by distance travelled per click
            disp = np.mean(disp)                                                # Take mean encoder value
            self.encoder_last = encoder_data
        return disp
