#!/usr/bin/env python

import rospy
import cv_bridge
from sensor_msgs.msg import Image

from get_message import GetMessage


class Camera(object):

    def __init__(self, nb, buggy_nb):
        self._callback = GetMessage()
        self.bridge = cv_bridge.CvBridge()
        topic = "buggy" + str(buggy_nb) + "/sonar" + str(nb)
        rospy.Subscriber(topic, Image, self._callback)
        rospy.Subscriber(topic, Image, self._callback)

    def get_image(self):
        image = self._callback.get_msg
        image = self.bridge.imgmsg_to_cv2(image, "passthrough")
        return image
