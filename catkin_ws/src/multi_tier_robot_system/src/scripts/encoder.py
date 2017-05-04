#!/usr/bin/env python

import rospy
from get_message import GetMessage
from std_msgs.msg import Int64


class Encoder(object):

    def __init__(self, nb, buggy_nb=0, step=17.5 / 18):
        self.nb = nb 												# Encoder id number
        self.step = step	 										# Distance travelled per click
        self.count = 0												# Encoder count
        self._callback = GetMessage() 								# Callback (private)
        topic = "buggy" + str(buggy_nb) + "/encoder" + str(nb)		# i.e. buggy0/encoder/0
        self.subscribe(topic) 										# Subscribe to topic

    # Subscribe to a given topic
    def subscribe(self, topic):
        rospy.Subscriber(topic, Int64, self._callback)

    # Read and return encoder data
    def read(self):
        self.count = self._callback.get_msg().data
        return self.count
