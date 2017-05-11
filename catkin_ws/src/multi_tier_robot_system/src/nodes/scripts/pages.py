#! /usr/bin/env python

import cv2
import pygame
import numpy as np
from colors import light_gray


class HomePage(object):

    def __init__(self, window, scale=1):
        self.window = window
        self.w, self.h = window.get_size()
        self.scale = scale

    # Show home page
    def show(self, buggy):
        camera_rect = (self.w / 32, self.h / 16, self.w * 59 / 128, self.h / 2)
        map_rect = (self.w * 65 / 128, self.h / 16, self.w * 59 / 128, self.h / 2)
        draw_camera(self.window, camera_rect, buggy)
        draw_map(self.window, map_rect, buggy, buggy.grid, self.scale)


def draw_map(display, rect, buggy, grid, scale=1, boarder_col=(0, 0, 0), frame_width=3):
    centre = (rect[0] + rect[2] / 2, rect[1] + rect[3] / 2) 						# Centre of map window
    origin = (centre[0] + buggy.pos[0] * scale, centre[1] + buggy.pos[1] * scale) 	# Coordinates of map origin
    grid.draw(display, origin, rect, scale=scale, line_col=light_gray)				# Draw grid world
    draw_axes(display, rect, origin) 												# Draw axis (based on origin)
    pygame.draw.rect(display, boarder_col, rect, frame_width)						# Draw window frame
    buggy.draw(display, centre, scale)


def draw_axes(display, rect, origin):
    if rect[0] < origin[0] < rect[0] + rect[2]:   		 			# If y-axis is in rectangle
        p1 = (origin[0], rect[1])
        p2 = (origin[0], rect[1] + rect[3])
        pygame.draw.line(display, (0, 0, 0), p1, p2, 2)				# Draw y-axis
    if rect[1] < origin[1] < rect[1] + rect[3]:						# If x-axis is in rectangle
        p1 = (rect[0], origin[1])
        p2 = (rect[0] + rect[2], origin[1])
        pygame.draw.line(display, (0, 0, 0), p1, p2, 2) 			# Draw xaxis'


def draw_camera(window, rect, buggy, boarder_col=(0, 0, 0), frame_width=3):
    frame = buggy.get_frame()
    if frame is not False:
        frame = cv2.resize(frame, (rect[2], rect[3]))
        frame = np.rot90(frame)
        surf = pygame.surfarray.make_surface(frame)
        window.blit(surf, (rect[0], rect[1]))
    pygame.draw.rect(window, boarder_col, rect, frame_width)

