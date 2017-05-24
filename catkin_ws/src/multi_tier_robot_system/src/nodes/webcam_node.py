#!/usr/bin/env python

import cv2
import rospy
import numpy as np
from sensor_msgs.msg import CompressedImage


class CameraNode(object):

    def __init__(self, camera=0, nb=0, buggy_nb=0, node_name="camera_node"):
        self.vc = cv2.VideoCapture(camera)                                      # Initialise instance of video capture
        self.rate = 25                                                          # Maximum frequency
        topic_name = "buggy"+str(buggy_nb)+"/camera"+str(nb)
        rospy.init_node(node_name, anonymous=True)                              # Initialise ros node
        self.publisher = rospy.Publisher(topic_name, CompressedImage, queue_size=1)     # Initialise publisher

    def main(self):
        message = CompressedImage()                                             # Ros compressed image
        r = rospy.Rate(self.rate)
        while True:
            _, frame = self.vc.read()									        # Read frame
            message.format = "jpeg"                                             # Give image format to message
            message.data = np.array(cv2.imencode(".jpg", frame)[1]).tostring()  # Encode captured image
            self.publisher.publish(message)										# Publish message
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
            r.sleep()
        self.vc.release()							                                    # Release capture
        cv2.destroyAllWindows()						                                    # Destroy all windows

if __name__ == '__main__':
    cn = CameraNode()
    cn.main()
