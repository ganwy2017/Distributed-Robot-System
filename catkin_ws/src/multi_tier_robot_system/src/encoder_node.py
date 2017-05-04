#!/usr/bin/env python

import rospy
import RPi.GPIO as GPIO
from time import sleep
from std_msgs.msg import Int64


class EncoderNode(object):

    def __init__(self, clk, dt, buggy_nb, node_name="encoder_node"):
        if len(clk) != len(dt):                                     # Check array lengths
            print("Error: The number of clk pins and dt pins must be equal.")
            return
        self.n = len(clk)                                           # Number of encoders
        self.clk = clk                                              # Set CLK pin 
        self.dt = dt                                                # Set DT pin
        self.setup_pins()                                           # Set pin modes
        self.clk_last = [GPIO.input(pin) for pin in self.clk]       # Initialise state of each clk
        self.node_name = node_name                                  # Set node name
        self.counter = [0] * self.n                                 # Initialise counter
        self.rate = 200                                             # Frequency
        self.main()

    def setup_pins(self):
        GPIO.setmode(GPIO.BCM)                                      # Use BCM numbering system
        GPIO.setup(self.clk, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)   # Set CLK pins to input
        GPIO.setup(self.dt, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)    # Set DT pins to input

    def encoder(self):
        for i in range(self.n):
            clk_state = GPIO.input(self.clk[i])             # Read clk
            dt_state = GPIO.input(self.dt[i])               # Read dt
            if clk_state != self.clk_last[i]:               # If clk state has changed
                if dt_state == clk_state:                   # If different to dt
                    self.counter[i] += 1                    # Update count
                else:
                    self.counter[i] -= 1                    # Update count
            self.clk_last[i] = clk_state                    # Update last state
        
    def main(self):
        rospy.init_node(self.node_name, anonymous=True)     # Initialise node
        publishers = []                                     # Initialise list of publishers
        for i in range(self.n):                             # Fill list of publishers
            topic = "buggy" + str(buggy_nb) + "/encoder" + str(i)
            publishers.append(rospy.Publisher(topic, Int64, queue_size=1))
        r = rospy.Rate(self.rate)
        try:
            while True:
                self.encoder()                              # Check encoders
                for publisher, count in zip(publishers, self.counter):
                    publisher.publish(count)                # Publish message
                r.sleep()
        finally:
            GPIO.cleanup()                                  # Return channels to defaults

        
if __name__ == "__main__":
    buggy_nb = 0
    clk = [17, 23]                                          # [Left encoder pin, right encoder pin]
    dt = [18, 22]                                           # [Left encoder pin, right encoder pin]
    EncoderNode(clk, dt, buggy_nb)
