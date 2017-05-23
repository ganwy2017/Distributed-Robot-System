#!/usr/bin/env python

import rospy
import pigpio
from std_msgs.msg import Float32


class ServoNode(object):

    def __init__(self, servo_numbers, data_pins, buggy_nb, node_name="servo_node"):
        self.servo_numbers = servo_numbers
        self.data_pins = data_pins
        self.rate = 10
        self.pi = pigpio.pi()
        self._setup_pins()
        self._setup_subscribers(buggy_nb)
        rospy.init_node(node_name, anonymous=True)                          # Initialise node

    def _setup_subscribers(self, buggy_nb):
        for nb, pin in zip(* (self.servo_numbers, data_pins)):              # Fill list of publishers
            topic = "buggy" + str(buggy_nb) + "/servo" + str(nb)
            rospy.Subscriber(topic, Float32, self._callback, [pin])

    def _callback(self, message, args):
        self.pi.set_servo_pulsewidth(args[0], message.data)

    def _setup_pins(self):
        for pin in self.data_pins:
            self.pi.set_mode(pin, pigpio.OUTPUT)                            # Set pins to output

    def main(self):
        r = rospy.Rate(self.rate)
        while True:
            r.sleep()


if __name__ == "__main__":
    buggy_nb = 0
    data_pins = [27, 4]
    servo_numbers = [0, 1]
    sn = ServoNode(servo_numbers, data_pins, buggy_nb)
    sn.main()
