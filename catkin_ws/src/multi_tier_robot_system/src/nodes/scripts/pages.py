#! /usr/bin/env python

import cv2
import copy
import pygame
import numpy as np
import scripts.widgets as widgets
import colors


class HomePage(object):

    def __init__(self, window, font, scale=1):
        self.window = window
        self.font = font
        self.w, self.h = window.get_size()
        self.scale = scale
        self.plus_button = widgets.Button(self.window, "+",
                                     (self.w * 5.0 / 8, 5.0 / 8 * self.h),
                                     (self.w / 16, self.h / 16),
                                     colors.gray,
                                     colors.light_gray,
                                     self.font(self.h / 32))
        self.minus_button = widgets.Button(self.window, "-",
                                       (self.w * 7.0 / 8, 5.0 / 8 * self.h),
                                       (self.w / 16, self.h / 16),
                                       colors.gray,
                                       colors.light_gray,
                                       self.font(self.h / 32))
        self.mode_button = widgets.Button(self.window, "",
                                       (self.w * 3.0 / 4, 6.0 / 8 * self.h),
                                       (self.w / 8, self.h / 16),
                                       colors.green,
                                       colors.pale_green,
                                       self.font(self.h / 32))

    # Show home page
    def show(self, buggy):
        camera_rect = (self.w / 32, self.h / 16, self.w * 59 / 128, self.h / 2)
        map_rect = (self.w * 65 / 128, self.h / 16, self.w * 59 / 128, self.h / 2)
        draw_camera(self.window, camera_rect, buggy)
        draw_map(self.window, map_rect, buggy, buggy.grid, self.scale)
        self._handle_buttons(buggy)
        pygame.display.update()

    def _handle_buttons(self, buggy):
        widgets.text(self.window, "Zoom",
                     colors.black,
                     (self.w * 3.0 / 4, 5.0 / 8 * self.h),
                     self.font(self.h / 32))
        self.plus_button.show()
        self.minus_button.show()
        self.mode_button.show()
        if self.mode_button.pressed:
            i = buggy.modes.index(buggy.mode) + 1
            if i >= len(buggy.modes):
                i = 0
            buggy.mode = buggy.modes[i]
        i = (buggy.modes.index(buggy.mode)) + 1
        if i >= len(buggy.modes):
            i = 0
        self.mode_button.text = buggy.modes[i]

        if self.plus_button.pressed:
            self.scale += 0.2
        elif self.minus_button.pressed:
            self.scale -= 0.2
        self._limit_scale()

    def _limit_scale(self):
        if self.scale < 0.6:
            self.scale = 0.6
        elif self.scale > 3.4:
            self.scale = 3.4


def draw_map(display, rect, buggy, grid, scale=1, boarder_col=(0, 0, 0), frame_width=3):
    centre = (rect[0] + rect[2] / 2, rect[1] + rect[3] / 2) 						# Centre of map window
    origin = (centre[0] - buggy.pos[0] * scale, centre[1] + buggy.pos[1] * scale) 	# Coordinates of map origin
    grid.draw(display, origin, rect, scale=scale, line_col=colors.light_gray)	    # Draw grid world
    draw_axes(display, rect, origin) 												# Draw axis (based on origin)
    pygame.draw.rect(display, boarder_col, rect, frame_width)						# Draw window frame
    buggy.draw(display, centre, scale)


def draw_axes(display, rect, origin):
    if rect[0] < origin[0] < rect[0] + rect[2]:   		 			                # If y-axis is in rectangle
        p1 = (origin[0], rect[1])
        p2 = (origin[0], rect[1] + rect[3])
        pygame.draw.line(display, colors.black, p1, p2, 2)				            # Draw y-axis
    if rect[1] < origin[1] < rect[1] + rect[3]:						                # If x-axis is in rectangle
        p1 = (rect[0], origin[1])
        p2 = (rect[0] + rect[2], origin[1])
        pygame.draw.line(display, colors.black, p1, p2, 2) 			                # Draw x-axis


def draw_camera(window, rect, buggy, boarder_col=(0, 0, 0), frame_width=3):
    frame = copy.deepcopy(buggy.get_frame())
    if frame is not False:
        frame = cv2.resize(frame, (rect[2], rect[3]))
        frame = np.fliplr(frame)
        frame = np.rot90(frame)
        surf = pygame.surfarray.make_surface(frame)
        window.blit(surf, (rect[0], rect[1]))
    pygame.draw.rect(window, boarder_col, rect, frame_width)

