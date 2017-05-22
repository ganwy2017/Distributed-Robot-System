#!/usr/bin/env python

import cv2
import rospy
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import CompressedImage

from get_message import GetMessage


class Camera(object):

    def __init__(self, nb, buggy_nb):
        self.get_image = GetMessage()
        self.bridge = CvBridge()
        topic = "buggy" + str(buggy_nb) + "/camera" + str(nb)
        rospy.Subscriber(topic, CompressedImage, self.get_image, queue_size=1)

    def get_frame(self):
        frame = self.get_image.get_msg().data
        frame = np.fromstring(frame, np.uint8)
        frame = cv2.imdecode(frame, cv2.IMREAD_COLOR)
        frame = np.stack((frame[:, :, 2], frame[:, :, 1], frame[:, :, 0]), axis=2)
        return frame
