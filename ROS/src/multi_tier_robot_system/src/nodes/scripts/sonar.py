#!/usr/bin/env python

import rospy
import pygame
import math
from std_msgs.msg import Int64
from get_data import GetData


class Sonar(object):

    def __init__(self, nb=0, pos=(0, 0), angle=0, eff_angle=0.17, col=(0, 0, 255), buggy_nb=0):
        self.nb = nb
        self.col = col
        self.local_pos = pos                            # Position relative to centre of buggy (cm)
        self.global_pos = pos                           # Position of the sensor in the world frame (cm)
        self.local_angle = angle                        # Angle relative to the buggy (rad)
        self.global_angle = angle                       # Angle of the sensor in the world frame (rad)
        self.eff_angle = eff_angle                      # Effective angle of sonar (rad)
        self.buggy_nb = buggy_nb                        # Buggy id number
        self.data = 150                                 # Measured value of sensor (cm)
        self._callback = GetData()
        topic = "buggy" + str(buggy_nb) + "/sonar/" + str(nb)
        self.subscribe(topic)

    # Subscribe to a given topic
    def subscribe(self, topic):
        rospy.Subscriber(topic, Int64, self._callback)
        
    # Update global coordinates of sensor given bugggy position and angle and return sensor reading
    def update(self, buggy_pos, buggy_angle): 
        self.global_pos = self._transform(buggy_pos, buggy_angle)
        self.global_angle = self.local_angle + buggy_angle
        self.data = self._callback.get_msg().data

    # Draw sensor given display, position on screen and scale
    def draw(self, display, buggy_pos, buggy_angle, scale=1):    
        pos = self._transform(buggy_pos, buggy_angle, scale=scale, flip=True)
        angle = self.local_angle + buggy_angle
        pos = [int(n) for n in pos]
        pygame.draw.circle(display, self.col, pos, 2 * scale)                       # Draw sensor
        if self.data > 3:
            data = self.data * scale
            rect = (pos[0] - data, pos[1] - data, 2 * data, 2 * data)
            start_angle = - self.eff_angle - angle + math.pi / 2
            end_angle = self.eff_angle - angle + math.pi / 2
            pygame.draw.arc(display, self.col, rect, start_angle, end_angle, 2)     # Draw sensor arc  

    # Transform sensor body given buggy position, angle (and scale for drawing purposes)
    def _transform(self, buggy_pos, buggy_angle, scale=1, flip=False):
        if flip: 
            flip = -1
        else:
            flip = 1
        buggy_x = buggy_pos[0]
        buggy_y = buggy_pos[1]
        local_x = float(self.local_pos[0])
        local_y = float(self.local_pos[1])
        if local_y:                                   
            angle = math.atan(local_x / local_y) + buggy_angle
        else:
            if local_x > 0:
                angle = buggy_angle + math.pi
            if local_x < 0:
                angle = buggy_angle - math.pi
            else:
                angle = buggy_angle
        l = math.sqrt(local_x ** 2 + local_y ** 2)
        x = round(l * math.sin(angle) * scale + buggy_x, 0)
        y = round(flip * l * math.cos(angle) * scale + buggy_y, 0)
        return [x, y]                                             

