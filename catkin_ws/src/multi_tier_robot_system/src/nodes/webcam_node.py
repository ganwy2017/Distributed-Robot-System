#!/usr/bin/env python

import cv2
import rospy
import numpy as np
from sensor_msgs.msg import CompressedImage


class CameraNode(object):

    def __init__(self, camera=0, nb=0, buggy_nb=0, node_name="camera_node"):
        self.vc = cv2.VideoCapture(camera)
        self.rate = 25
        topic_name = "buggy"+str(buggy_nb)+"/camera"+str(nb)
        rospy.init_node(node_name, anonymous=True)
        self.publisher = rospy.Publisher(topic_name, CompressedImage, queue_size=1)

    def main(self):
        message = CompressedImage()
        r = rospy.Rate(self.rate)
        while True:
            _, frame = self.vc.read()													# Read frame
            message.format = "jpeg"
            message.data = np.array(cv2.imencode(".jpg", frame)[1]).tostring()
            self.publisher.publish(message)												# Publish frame
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
            r.sleep()
        self.vc.release()							# Release capture
        cv2.destroyAllWindows()						# Destroy all windows

if __name__ == '__main__':
    cn = CameraNode()
    cn.main()
