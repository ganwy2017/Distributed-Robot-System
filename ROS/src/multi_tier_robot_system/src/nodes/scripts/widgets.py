import pygame
from myFunctions import point_in_poly


def text(display, text, col, pos, font):
    text_surf = font.render(text, True, col)
    text_rect = text_surf.get_rect()
    text_rect.center = (pos[0], pos[1])
    display.blit(text_surf, text_rect)


def button(display, text, pos, size, inactive_col, active_col, font):
    rect = (pos[0] - size[0] / 2, pos[1] - size[1] / 2, size[0], size[1])
    cur = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    pressed = False
    if pos[0] - size[0] / 2 < cur[0] < pos[0] + size[0] / 2 \
            and pos[1] - size[1] / 2 < cur[1] < pos[1] + size[1] / 2:
        pygame.draw.rect(display, active_col, rect)
        if click[0] == 1:
            pressed = True
    else:
        pygame.draw.rect(display, inactive_col, rect)
    text(display, text, (0, 0, 0), pos, font)
    return pressed


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
        if point_in_poly(cur, tab) and click[0] == 1:                               # If cursor is on tab and click
            current_page = page_list[i]                                             # Set current page to this page
    return current_page
