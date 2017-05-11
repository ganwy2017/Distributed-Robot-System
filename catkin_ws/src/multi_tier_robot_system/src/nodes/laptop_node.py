#! /usr/bin/env python

# Standard libraries
import yaml
import rospy
import math
import pygame

# My libraries/ Modules
import scripts.colors as colors					    # Import all colors
import scripts.widgets as widgets  					# Import all widgets
import scripts.pages as pages				        # Import all pages
from scripts.fonts import blackops as font		    # Import blackops from
from scripts.keyboard_dict import key_dict			# Import dictionary of key values

# Buggy Objects
from scripts.buggy import Buggy 				    # Import Buggy module
from scripts.sonar import Sonar 				    # Import sonar module
from scripts.encoder import Encoder                 # Import Encoder module
from scripts.servo import Servo                     # Import Servo module
from scripts.camera import Camera                   # Import Camera module


class LaptopNode(object):

    def __init__(self):
        # Pygame and window
        pygame.font.init()
        self.size = (1500, 1000)										    # Set window size
        self.window = pygame.display.set_mode(self.size)				    # Initialise window for app
        pygame.display.set_caption("Robot Control Suite") 				    # Set caption
        self.quit = False												    # App will quit when quit is
        self.mode = "manual"
        self.fps = 50													    # Frame rate of app

        # Node
        rospy.init_node("laptop", anonymous=True)

        # Initialise Pages
        self.pages = ("Home", "Settings") 								    # List of page names
        self.current_page = "Home" 										    # Current page
        self.home = pages.HomePage(self.window, scale=1)			        # Initialise home page

        # Events
        self.key_status = {} 											    # Initialise status of keys
        [self.key_status.update({key: False}) for key in key_dict]  	    # Fill key dictionary

        # Buggies
        self.buggy = None
        self._create_buggies()
        self.main()

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

    def _create_buggies(self):
        config_file = open("config/buggy.yaml")
        config = yaml.safe_load(config_file)
        config_file.close()
        for _, setup in config.iteritems():
            sonars = []
            encoders = []
            servos = []
            cameras = []
            for key, value in setup.iteritems():
                if "sonar" in key:
                    sonars.append(Sonar(setup[key]["number"],
                                        0,
                                        pos=setup[key]["position"],
                                        angle=math.radians(setup[key]["angle"])))
                if "encoder" in key:
                    encoders.append(Encoder(setup[key]["number"],
                                            0))
                if "servo" in key:
                    servos.append(Servo(setup[key]["number"],
                                        0,
                                        orientation=setup[key]["orientation"]))
                if "camera" in key:
                    cameras.append(Camera(setup[key]["number"],
                                   0))
            self.buggy = Buggy(sonars=sonars, encoders=encoders, servos=servos, cameras=cameras)

    def _update_window(self):
        rect = (self.size[0] / 64, self.size[1] / 64, self.size[0] * 31 / 32, self.size[1] * 31 / 32)
        tab_size = (self.size[0] / 8, self.size[1] / 32)
        self.window.fill(colors.white)
        self.current_page = widgets.tabs(self.window, self.pages, self.current_page, rect, tab_size, font(self.size[1] / 64))
        if self.current_page == "Home":
            self.home.show(self.buggy)
        pygame.display.update()

    def _keypress2drive(self):
        up = self.key_status["k_up"]
        down = self.key_status["k_down"]
        left = self.key_status["k_left"]
        right = self.key_status["k_right"]
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
        return left, right

    def _keypress2servo(self):
        if self.key_status["k_a"]:
            yaw = -1.0
        elif self.key_status["k_d"]:
            yaw = 1.0
        elif self.key_status["k_s"]:
            yaw = "reset"
        else:
            yaw = 0
        if self.key_status["k_w"]:
            pitch = 1.0
        elif self.key_status["k_s"]:
            pitch = -1.0
        else:
            pitch = 0
        return [pitch, yaw]

    def main(self):
        self._update_window()
        while not self.quit:
            self._event_handler()
            if self.mode == "manual":
                left, right = self._keypress2drive()
            elif self.mode == "automatic":
                left = 0
                right = 0
            delta_servo_dict = self._keypress2servo()
            self.buggy.update(left, right, delta_servo_dict)
            self._update_window()


if __name__ == "__main__":
    LaptopNode()
