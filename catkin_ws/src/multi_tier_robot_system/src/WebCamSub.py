#!/usr/bin/env python

import cv2
import rospy
from scripts.get_message import GetMessage
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


class DisplayNode(object):

    def __init__(self):
        self.node_name = "DisplayNode"
        self.topic_name = "buggy0/camera0"
        self.bridge = CvBridge()
        self.main()

    def main(self):
        get_image = GetMessage()
        rospy.init_node(self.node_name, anonymous=True)
        rospy.Subscriber(self.topic_name, Image, get_image)								# Initialise subscriber
        cv2.namedWindow("webcam")
        while True:
            frame = get_image.get_msg()
            frame = self.bridge.imgmsg_to_cv2(frame, "passthrough")
            height, width, _ = frame.shape
            frame = cv2.resize(frame, (width * 3, height * 3))
            cv2.imshow("webcam", frame)
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

        cv2.destroyAllWindows()						# Destroy all windows

if __name__ == '__main__':
    DisplayNode()
