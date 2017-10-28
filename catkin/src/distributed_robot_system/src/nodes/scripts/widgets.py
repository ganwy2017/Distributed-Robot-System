import pygame
import time
import scripts.helpers as helpers


class Button(object):

    def __init__(self, display, text, pos, size, inactive_col, active_col, font, reset_time=0.2):
        self.last_pressed = time.time()
        self.reset_time = reset_time
        self.display = display
        self.text = text
        self.pos = pos
        self.size = size
        self.inactive_col = inactive_col
        self.active_col = active_col
        self.font = font
        self.pressed = False

    def show(self):
        rect = (self.pos[0] - self.size[0] / 2,
                self.pos[1] - self.size[1] / 2,
                self.size[0],
                self.size[1])
        cur = pygame.mouse.get_pos()
        click = pygame.mouse.get_pressed()
        pressed = False
        within_x = self.pos[0] - self.size[0] / 2 < cur[0] < self.pos[0] + self.size[0] / 2
        within_y = self.pos[1] - self.size[1] / 2 < cur[1] < self.pos[1] + self.size[1] / 2
        if within_x and within_y:
            pygame.draw.rect(self.display, self.active_col, rect)
            if click[0] == 1:
                if time.time() - self.last_pressed > self.reset_time:
                    self.last_pressed = time.time()
                    pressed = True
        else:
            pygame.draw.rect(self.display, self.inactive_col, rect)
        text(self.display, self.text, (0, 0, 0), self.pos, self.font)
        self.pressed = pressed


def text(display, message, col, pos, font):
    text_surf = font.render(message, True, col)
    text_rect = text_surf.get_rect()
    text_rect.center = (pos[0], pos[1])
    display.blit(text_surf, text_rect)


def tabs(display, page_list, current_page, rect, tab_size, font,
         line_col=(0, 0, 0), text_col=(0, 0, 0), line_width=3):
    # Function to draw a series of tabs dictated by the page_list and current page
    # Output: current page
    bbox = (rect[0], rect[1], rect[0] + rect[2], rect[1] + rect[3])                 # Bounding box of widget
    page_nb = page_list.index(current_page)                                         # Number of current tab
    cur = pygame.mouse.get_pos()                                                    # Cursor position
    click = pygame.mouse.get_pressed()                                              # True if click
    frame = ((bbox[0] + page_nb * tab_size[0], bbox[1] + tab_size[1]),              # Points list for the frame
             (bbox[0], bbox[1] + tab_size[1]),
             (bbox[0], bbox[3]),
             (bbox[2], bbox[3]),
             (bbox[2], bbox[1] + tab_size[1]),
             (bbox[0] + (page_nb + 1) * tab_size[0], bbox[1] + tab_size[1]))
    pygame.draw.lines(display, line_col, False, frame, line_width)                  # Draw the frame
    for i in range(len(page_list)):                                         
        tab = ((bbox[0] + i * tab_size[0], bbox[1] + tab_size[1]),                  # Points list for tab
               (bbox[0] + i * tab_size[0] + tab_size[1] / 2, bbox[1]),
               (bbox[0] + (i + 1) * tab_size[0] - tab_size[1] / 2, bbox[1]),
               (bbox[0] + (i + 1) * tab_size[0], bbox[1] + tab_size[1]))
        pygame.draw.lines(display, line_col, False, tab, line_width)                # Draw tab
        text(display, page_list[i], text_col,
             (bbox[0] + tab_size[0] * (i + 0.5), bbox[1] + tab_size[1] / 2), font)   # Label tab
        if helpers.point_in_poly(cur, tab) and click[0] == 1:                               # If cursor is on tab and click
            current_page = page_list[i]                                             # Set current page to this page
    return current_page
