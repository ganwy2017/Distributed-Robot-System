#! /usr/bin/env python

# Standard libraries
import yaml
import rospy
import math
import pygame

# My libraries
import scripts.colors as colors					    # Import all colors
import scripts.widgets as widgets  					# Import all my widgets
import scripts.pages as pages				        # Import all pages
from scripts.fonts import blackops as font		    # Import blackops and use it as the font
from scripts.keyboard_dict import key_dict			# Import dictionary of keyboard key names

# Buggy Objects
from scripts.buggy import Buggy 				    # Import Buggy module
from scripts.sonar import Sonar 				    # Import sonar module
from scripts.encoder import Encoder                 # Import Encoder module
from scripts.servo import Servo                     # Import Servo module
from scripts.camera import Camera                   # Import Camera module
from scripts.gyroscope import Gyroscope             # Import Gyroscope module


class LaptopNode(object):

    def __init__(self):
        pygame.font.init()
        self.size = (1500, 1000)										    # Set window size
        self.window = pygame.display.set_mode(self.size)				    # Initialise window for app
        pygame.display.set_caption("Robot Control Suite") 				    # Set caption
        self.quit = False												    # App will quit when quit is
        self.fps = 25													    # Frame rate of app
        rospy.init_node("laptop", anonymous=True)                           # Initialise ros node
        self.pages = ("Home", "Settings") 								    # List of page names
        self.current_page = "Home" 										    # Current page
        self.home = pages.HomePage(self.window,
                                   font,
                                   scale=1)			                        # Initialise home page
        self.key_status = {} 											    # Initialise status of keys
        [self.key_status.update({key: False}) for key in key_dict]  	    # Fill key dictionary
        self.buggy = None
        self._create_buggy()                                                # Initialise buggy object

    def _event_handler(self):
        for event in pygame.event.get():							        # Get all pygame events
            if event.type == pygame.QUIT:							        # If an event is of type quit
                self.quit = True
            elif event.type == pygame.KEYDOWN:						        # If key event is key down
                for key, value in key_dict.iteritems():
                    if event.key == value:
                        self.key_status[key] = True					        # Update key_status dictionary
                        break
            elif event.type == pygame.KEYUP: 						        # If key event is key up
                for key, value in key_dict.iteritems():
                    if event.key == value:
                        self.key_status[key] = False				        # Update key_status dictionary
                        break

    def _create_buggy(self):
        config_file = open("config/buggy.yaml")                             # Open configuration file
        config = yaml.safe_load(config_file)                                # Load file into config
        config_file.close()                                                 # Close file
        for _, setup in config.iteritems():
            print setup["number"]
            sonars = []
            encoders = []
            servos = []
            cameras = []
            gyroscopes = []
            for key, value in setup.iteritems():
                if "sonar" in key:                                          # If "sonar" is in the device name
                    sonars.append(Sonar(setup[key]["number"],               # Initialise sonar object with given configurations
                                        setup["number"],
                                        setup[key]["position"],
                                        math.radians(setup[key]["angle"]),
                                        setup[key]["min_dist"],
                                        setup[key]["action"]))
                elif "encoder" in key:                                      # If "encoder" is in the device name
                    encoders.append(Encoder(setup[key]["number"],           # Initialise encode object with given configurations
                                            setup["number"]))
                elif "servo" in key:                                        # If "servo: is in device name
                    servos.append(Servo(setup[key]["number"],               # Initialise servo object with given configurations
                                        setup["number"],
                                        setup[key]["axis"],
                                        setup[key]["min"],
                                        setup[key]["max"]))
                elif "camera" in key:                                       # If "camera" is in device name
                    cameras.append(Camera(setup[key]["number"],             # Initialise camera object with given configurations
                                          setup["number"]))
                elif "gyroscope" in key:                                    # If "gyroscope" is in device name
                    gyroscopes.append((Gyroscope(setup[key]["number"],      # Initialise gyroscope object with given congfigs
                                                 setup["number"],
                                                 axis=setup[key]["axis"])))
            self.buggy = Buggy(sonars=sonars,                               # Initialise buggy with device objects
                               encoders=encoders,
                               servos=servos,
                               cameras=cameras,
                               gyroscopes=gyroscopes)

    def _update_window(self):
        rect = (self.size[0] / 64, self.size[1] / 64, self.size[0] * 31 / 32, self.size[1] * 31 / 32)
        tab_size = (self.size[0] / 8, self.size[1] / 32)
        self.window.fill(colors.white)                                                          # Set window color to white
        self.current_page = widgets.tabs(self.window, self.pages, self.current_page, rect, tab_size, font(self.size[1] / 64))
        if self.current_page == "Home":                                                         # If current page is Home
            self.home.show(self.buggy)                                                          # Show home page

    def _keypress2drive(self):
        # Returns a list of drive values intended for the motors given the current key statuses
        up = self.key_status["k_w"]
        down = self.key_status["k_s"]
        left = self.key_status["k_a"]
        right = self.key_status["k_d"]
        if up and not down and not left and not right:
            left = 255
            right = 255
        elif not up and down and not left and not right:
            left = -255
            right = -255
        elif not up and not down and left and not right:
            left = -255
            right = 255
        elif not up and not down and not left and right:
            left = 255
            right = -255
        else:
            left = 0
            right = 0
        return [left, right]

    def _keypress2servo(self):
        # Returns a list of drive values intended for the motors given the current key statuses
        d_pitch = 0
        d_yaw = 0
        if self.key_status["k_kp4"]:
            d_pitch = 1.0
        elif self.key_status["k_kp6"]:
            d_pitch = -1.0
        if self.key_status["k_kp8"]:
            d_yaw = 1.0
        elif self.key_status["k_kp2"]:
            d_yaw = -1.0
        if self.key_status["k_kp5"]:
            d_pitch = "reset"
            d_yaw = "reset"
        return [d_pitch, d_yaw]

    def main(self):
        self._update_window()
        while not self.quit:
            self._event_handler()                       # Update key_status dict given keypress events
            if self.buggy.mode == "Manual":
                drive_cmd = self._keypress2drive()      # Get drive values based on key_status
            elif self.buggy.mode == "Roam":
                drive_cmd = [200, 200]
            servo_cmd = self._keypress2servo()          # Get servo values based on key_status
            self.buggy.update(drive_cmd, servo_cmd)
            self._update_window()


if __name__ == "__main__":
    ln = LaptopNode()
    ln.main()
