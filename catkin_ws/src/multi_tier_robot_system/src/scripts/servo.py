#!/usr/bin/env python

import rospy


class Motors(object):

    def __init__(self, nb):
        self.pos = 0
        # self.message = Drive()
        topic = "buggy" + str(nb) + "/servo0"
        # self.publisher = rospy.Publisher(topic, Drive, queue_size=1)

    # Update attributes and publish motor speeds
    def move(self):
        pass

    # Update attributes given left and right motor speeds
    def update(self, left, right):
        pass
