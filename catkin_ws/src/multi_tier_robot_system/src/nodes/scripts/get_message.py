#!/usr/bin/env python

import threading
import copy


class GetMessage(object):

    def __init__(self):
        self.event = threading.Event()
        self.msg = None
        self.flag = False                   # Flag to signify when msg is accessed

    def __call__(self, msg):
        while self.flag:                    # While flag is true
            pass                            # Wait
        self.flag = True                    # Set flag to True
        self.msg = msg                      # Write msg
        self.flag = False                   # Set flag to false
        self.event.set()

    def get_msg(self, timeout=None):
        self.event.wait(timeout)
        while self.flag:                    # While msg is being written
            pass                            # Wait
        self.flag = True                    # Set flag to True
        msg = copy.deepcopy(self.msg)       # Copy msg
        self.flag = False                   # Set flag to False
        return msg
