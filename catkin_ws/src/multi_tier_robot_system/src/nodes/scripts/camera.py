#!/usr/bin/env python

import rospy
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image

from get_message import GetMessage


class Camera(object):

    def __init__(self, nb, buggy_nb):
        self.get_image = GetMessage()
        self.bridge = CvBridge()
        topic = "buggy" + str(buggy_nb) + "/camera" + str(nb)
        rospy.Subscriber(topic, Image, self.get_image)

    def get_frame(self):
        frame = self.get_image.get_msg()
        frame = self.bridge.imgmsg_to_cv2(frame, "passthrough")
        return frame
