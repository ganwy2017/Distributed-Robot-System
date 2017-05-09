#!/usr/bin/env python

import rospy
import pigpio
from std_msgs.msg import Float32

class ServoNode(object):

    def __init__(self, servo_numbers, data_pins, buggy_nb, node_name="servo_node"):
        self.servo_numbers = servo_numbers
        self.data_pins = data_pins
        self.buggy_nb = buggy_nb
        self.node_name = node_name
        self.rate = 10
        self.setup_pins()
        self.pi = pigpio.pi()
        self.main()

    def callback(self, message, args):
        pin = args[0]
        print message.data
        self.pi.set_servo_pulswidth(pin, message.data)

    def setup_pins(self):
        for pin in self.data_pins:
            self.pi.set_mode(pin, pigpio.OUTPUT)                            # Set pins to output

    def main(self):
        rospy.init_node(self.node_name, anonymous=True)                     # Initialise node
        for nb, pin in zip(* (self.servo_numbers, data_pins)):              # Fill list of publishers
            topic = "buggy" + str(self.buggy_nb) + "/servo" + str(nb)
            rospy.Subscriber(topic, Float32, self.callback, [pin])
        r = rospy.Rate(self.rate)
        while True:
            r.sleep()
        # for pin in self.data_pins:
        #     self.pi.set_servo_pulsewidth(pin, 0)
        # self.pi.stop()

if __name__ == "__main__":
    buggy_nb = 0
    data_pins = [27]
    servo_numbers = [0]
    ServoNode(servo_numbers, data_pins, buggy_nb)
