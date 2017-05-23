#!/usr/bin/env python

import rospy
from get_message import GetMessage
from std_msgs.msg import Int64


class Encoder(object):

    def __init__(self, nb, buggy_nb, dist_per_tick=17.5 / 18):
        self.dist_per_tick = dist_per_tick	 						# Distance travelled per click
        self.count = 0												# Encoder count
        self._get_message = GetMessage() 								# Callback (private)
        topic = "buggy" + str(buggy_nb) + "/encoder" + str(nb)		# i.e. buggy0/encoder0
        rospy.Subscriber(topic, Int64, self._get_message) 				# Subscribe to topic

    def read(self):
        self.count = self._get_message.get_msg().data
        return self.count
