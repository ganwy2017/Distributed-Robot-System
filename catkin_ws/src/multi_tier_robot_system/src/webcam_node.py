#!/usr/bin/env python

import cv2
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


class CameraNode(object):

    def __init__(self, camera=0):
        self.vc = cv2.VideoCapture(camera)
        self.node_name = "camera_node"
        self.topic_name = "buggy0/camera0"
        self.bridge = CvBridge()
        self.main()

    def main(self):
        rospy.init_node(self.node_name, anonymous=True)
        pub_camera = rospy.Publisher(self.topic_name, Image, queue_size=1)			# Initialise publisher for motor controls
        while True:
            ret, frame = self.vc.read()													# Read frame
            camera_msg = self.bridge.cv2_to_imgmsg(frame, encoding="passthrough")		# Convert to ROS image message
            pub_camera.publish(camera_msg)												# Publish frame
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
        self.vc.release()							# Release capture
        cv2.destroyAllWindows()						# Destroy all windows

if __name__ == '__main__':
    CameraNode()
