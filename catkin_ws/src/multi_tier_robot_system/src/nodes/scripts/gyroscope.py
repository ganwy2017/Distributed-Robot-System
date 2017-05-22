#!/usr/bin/env python

import rospy
from std_msgs.msg import String

from get_message import GetMessage


class Gyroscope(object):

    def __init__(self, nb, buggy_nb, axis=0):
        self.get_message = GetMessage()
        self.axis = axis
        topic = "buggy" + str(buggy_nb) + "/gyroscope" + str(nb)
        rospy.Subscriber(topic, String, self.get_message, queue_size=1)

    def get_data(self):
        data = self.get_message.get_msg().data
        return data
