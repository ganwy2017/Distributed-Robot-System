#!/usr/bin/env python

import rospy
from multi_tier_robot_system.msg import Drive


class Motors(object):

    def __init__(self, nb):
        self.left = 0
        self.right = 0
        self.left_dir = True
        self.right_dir = True
        self.message_id = 0
        self.message = Drive()
        topic = "buggy" + str(nb) + "/drive"
        self.publisher = rospy.Publisher(topic, Drive, queue_size=1)

    # Update attributes and publish motor speeds
    def drive(self, left, right):
        self._update(left, right)
        self.message.left = self.left
        self.message.right = self.right
        self.message.left_dir = self.left_dir
        self.message.right_dir = self.right_dir
        self.message.id = self.message_id
        self.publisher.publish(self.message)
        self.message_id += 1
        if self.message_id == 100:
            self.message_id = 1

    # Update attributes given left and right motor speeds
    def _update(self, left, right):
        self.left = abs(left)
        self.right = abs(right)
        if left < 0:
            self.left_dir = False
        else:
            self.left_dir = True
        if right < 0:
            self.right_dir = False
        else:
            self.right_dir = True
