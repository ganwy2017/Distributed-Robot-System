#!/usr/bin/env python

import rospy
import RPi.GPIO as GPIO
from std_msgs.msg import Float32


def callback(message, args):
    pwm = args[0]
    print message.data
    pwm.ChangeDutyCycle(message.data)


class ServoNode(object):
    def __init__(self, servo_numbers, data_pins, buggy_nb, node_name="servo_node"):
        self.servo_numbers = servo_numbers
        self.data_pins = data_pins
        self.buggy_nb = buggy_nb
        self.node_name = node_name
        self.rate = 50
        self.pwms = []
        self.setup_pins()
        self.main()

    def setup_pins(self):
        GPIO.setmode(GPIO.BCM)                                              # Use BCM numbering system
        for pin in self.data_pins:
            GPIO.setup(pin, GPIO.OUT)                                       # Set pins to output
            pwm = GPIO.PWM(pin, 50)
            pwm.start(7.5)                                                  # Move servo to centre position
            self.pwms.append(pwm)

    def main(self):
        rospy.init_node(self.node_name, anonymous=True)                     # Initialise node
        for nb, pwm in zip(* (self.servo_numbers, self.pwms)):              # Fill list of publishers
            topic = "buggy" + str(self.buggy_nb) + "/servo" + str(nb)
            rospy.Subscriber(topic, Float32, callback, [pwm])
        r = rospy.Rate(self.rate)
        while True:
            r.sleep()
        # GPIO.cleanup()  # Return channels to defaults


if __name__ == "__main__":
    buggy_nb = 0
    data_pins = [27]
    servo_numbers = [0]
    ServoNode(servo_numbers, data_pins, buggy_nb)
