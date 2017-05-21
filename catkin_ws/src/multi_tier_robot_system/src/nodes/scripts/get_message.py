#!/usr/bin/env python

import threading
import copy
4

class GetMessage(object):

    def __init__(self):
        self.event = threading.Event()
        self.msg = None
        self.flag = False

    def __call__(self, msg):
        while self.flag:
            pass
        self.flag = True
        self.msg = msg
        self.flag = False
        self.event.set()

    def get_msg(self, timeout=None):
        self.event.wait(timeout)
        while self.flag:
            pass
        self.flag = True
        msg = copy.deepcopy(self.msg)
        self.flag = False
        return msg
