#!/usr/bin/env python

import rospy
import pygame
import math
from std_msgs.msg import Int32

# My modules
from get_message import GetMessage
import colors


class Sonar(object):

    def __init__(self, nb, buggy_nb, pos, angle, min_dist=10, action="None", eff_angle=0.17, col=colors.lime_green):
        self.col = col
        self.min_dist = min_dist
        self.action = action
        self.local_pos = pos                            # Position relative to centre of buggy (cm)
        self.global_pos = pos                           # Position of the sensor in the world frame (cm)
        self.local_angle = angle                        # Angle relative to the buggy (rad)
        self.global_angle = angle                       # Angle of the sensor in the world frame (rad)
        self.eff_angle = eff_angle                      # Effective angle of sonar (rad)
        self.data = 0                                   # Measured value of sensor (cm)
        self.get_message = GetMessage()
        topic = "buggy" + str(buggy_nb) + "/sonar" + str(nb)
        rospy.Subscriber(topic, Int32, self.get_message)
        
    def update(self, buggy_pos, buggy_angle):
        self.global_pos = self._transform(buggy_pos, buggy_angle)
        self.global_angle = -(self.local_angle + buggy_angle)
        self.data = self.get_message.get_msg().data

    def draw(self, display, buggy_pos, buggy_angle, scale=1):
        pos = self._transform(buggy_pos, buggy_angle, scale=scale, flip=True)
        angle = self.global_angle
        pos = [int(n) for n in pos]
        pygame.draw.circle(display, self.col, pos, int(2 * scale))                          # Draw sensor
        # NB: For low data values, drawing an arc is impossible
        if self.data > 5:
            data = self.data * scale                                                        # Scale sensor value with GUI
            rect = (pos[0] - data, pos[1] - data, 2 * data, 2 * data)                       # Calculate rect of arc
            start_angle = - self.eff_angle - angle + math.pi / 2                            # Depends of effective angle
            end_angle = self.eff_angle - angle + math.pi / 2
            pygame.draw.arc(display, self.col, rect, start_angle, end_angle, 2)             # Draw sensor arc

    def _transform(self, buggy_pos, buggy_angle, scale=1, flip=False):
        # Return position of sonar given buggy orientation and local sonar coordinates
        if flip:                                            # Flip argument is for drawing sonar position flipped vertically
            flip = -1
        else:
            flip = 1
        buggy_x = buggy_pos[0]
        buggy_y = buggy_pos[1]
        local_x = float(self.local_pos[0])
        local_y = float(self.local_pos[1])
        angle = math.atan(local_x / local_y)
        if local_y < 0:
            angle += math.pi
        angle -= buggy_angle
        l = math.sqrt(local_x ** 2 + local_y ** 2)
        x = l * math.sin(angle) * scale + buggy_x
        y = flip * l * math.cos(angle) * scale + buggy_y
        return [x, y]                                             
