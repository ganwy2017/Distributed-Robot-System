#! /usr/bin/env python

import numpy as np
from math import sin, cos
import pygame


class Grid(object):

    def __init__(self, size, res):
        self.size = size
        self.world = np.zeros((size, size)) 					# Grid world (map)
        self.res = res											# Resolution of grid

    # Update world based on sonar data
    def update(self, sonars):
        for sonar in sonars:
            hit, misses = self._ping(sonar)
            for i, j in misses:
                self.world[j][i] = 0
            if hit:
                self.world[hit[1]][hit[0]] = 1

    # Draw the grid world on a display in a given rect and the coordinates of the grid origin
    def draw(self, display, origin, rect, invalid_col=(255, 0, 0), line_col=(0, 0, 0), scale=1):
        self._draw_grid_lines(display, origin, rect, line_col, scale)
        self._draw_occupied_cells(display, origin, rect, invalid_col, scale)

    # Draw grid lines
    def _draw_grid_lines(self, display, origin, rect, col, scale):
        l = origin[0] - self.res * self.size / 2 * scale
        # r = origin[0] + self.res * self.size / 2 * scale
        t = origin[1] - self.res * self.size / 2 * scale
        # b = origin[1] + self.res * self.size / 2 * scale
        max_l = rect[0]
        max_r = rect[0] + rect[2]
        max_t = rect[1]
        max_b = rect[1] + rect[3]
        for i in range(self.size + 1):
            y = t + i * self.res * scale
            if max_t < y < max_b:
                p1 = (max_l, y)
                p2 = (max_r, y)
                pygame.draw.line(display, col, p1, p2)
            x = l + i * self.res * scale
            if max_l < x < max_r:
                p1 = (x, max_b)
                p2 = (x, max_t)
                pygame.draw.line(display, col, p1, p2)

    # Draw squares that objects have been detected in
    def _draw_occupied_cells(self, display, origin, rect, col, scale):
        i0 = self.size / 2 - (origin[0] - rect[0]) / self.res / float(scale) + 1
        j0 = self.size / 2 - (origin[1] - rect[1]) / self.res / float(scale) + 1
        i1 = self.size / 2 + (rect[0] + rect[2] - origin[0]) / self.res / float(scale)
        j1 = self.size / 2 + (rect[1] + rect[3] - origin[1]) / self.res / float(scale)
        i0, j0 = self._keep_in_grid((i0, j0))
        i1, j1 = self._keep_in_grid((i1, j1))
        for j in range(j0, j1):
            for i in range(i0, i1):
                if self.world[j][i] > 0.5:
                    p1 = origin[0] + (i - self.size / 2) * self.res * scale
                    p2 = origin[1] + (j - self.size / 2) * self.res * scale
                    rect = (p1, p2, self.res * scale, self.res * scale)
                    pygame.draw.rect(display, col, rect)

    # Ensure coordinates are in the grid world
    def _keep_in_grid(self, cell):
        i, j = cell
        if i < 0:
            i = 0
        elif i >= self.size:
            i = self.size - 1
        if j < 0:
            j = 0
        elif j >= self.size:
            j = self.size - 1
        return int(i), int(j)

    # Add grid opservations to detections as rects
    def _get_occupied_cells(self):
        cells = []
        for j in range(self.size):
            for i in range(self.size):
                if self.world[j][i]:
                    cells.append((i, j))
        return cells

    # Return grid cell given global coordinates
    def _coord2cell(self, pos):
        i = int(pos[0] / self.res + self.size / 2)
        j = int(self.size / 2 - pos[1] / self.res)
        return (i, j)

    # Calculate cell position of obstacle
    def _ping(self, sonar):
        if sonar.data:
            x = sonar.global_pos[0] + sonar.data * sin(sonar.global_angle)
            y = sonar.global_pos[1] + sonar.data * cos(sonar.global_angle)
            hit = self._coord2cell((x, y))
            hit = self._keep_in_grid(hit)
        else:
            hit = False
        misses = []
        for d in range(0, sonar.data, 2):
            x = sonar.global_pos[0] + d * sin(sonar.global_angle)
            y = sonar.global_pos[1] + d * cos(sonar.global_angle)
            miss = self._coord2cell((x, y))
            if miss not in misses:
                misses.append(miss)
        if misses:
            if misses[-1] == hit:
                del misses[-1]
        return hit, misses
