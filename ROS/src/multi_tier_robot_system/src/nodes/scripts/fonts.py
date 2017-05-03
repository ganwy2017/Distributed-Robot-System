import pygame


def blackops(size, style=None):
    path = "fonts/black-ops-one/"
    return pygame.font.Font(path + "BlackOpsOne-Regular.ttf", int(size))


def droid(size, style=None):
    path = "fonts/disposabledroid-bb/"
    if style == "bold" or style == "b":
        return pygame.font.Font(path + "DisposableDroidBB_bld.ttf", int(size))
    elif style == "italic" or style == "i":
        return pygame.font.Font(path + "DisposableDroidBB_ital.ttf", int(size))
    elif style == "bolditalic" or style == "bi":
        return pygame.font.Font(path + "DisposableDroidBB_bldital.ttf", int(size))
    else:
        return pygame.font.Font(path + "DisposableDroidBB.ttf", int(size))


def autodestruct(size, style=None):
    path = "fonts/autodestruct-bb/"
    if style == "bold" or style == "b":
        return pygame.font.Font(path + "autodestructbb_bold.ttf", int(size))
    else:
        return pygame.font.Font(path + "autodestructbb_reg.ttf", int(size))
