#!/usr/bin/env python

import cv2
import rospy
import numpy as np
from sensor_msgs.msg import Image
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge, CvBridgeError


class CameraNode(object):

    def __init__(self, camera=0):
        self.vc = cv2.VideoCapture(camera)
        self.node_name = "camera_node"
        self.topic_name = "buggy0/camera0"
        self.bridge = CvBridge()
        self.rate = 25
        self.main()

    def main(self):
        rospy.init_node(self.node_name, anonymous=True)
        pub_camera = rospy.Publisher(self.topic_name, CompressedImage)
        message = CompressedImage()
        r = rospy.Rate(self.rate)
        while True:
            ret, frame = self.vc.read()													# Read frame
            message.format = "jpeg"
            message.data = np.array(cv2.imencode(".jpg", frame)[1]).tostring()
            pub_camera.publish(message)												# Publish frame
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
            r.sleep()
        self.vc.release()							# Release capture
        cv2.destroyAllWindows()						# Destroy all windows

if __name__ == '__main__':
    CameraNode()
