#!/usr/bin/env python

import threading


class GetMessage(object):

    def __init__(self):
        self.event = threading.Event()
        self.msg = None

    def __call__(self, msg):
        self.msg = msg
        self.event.set()

    def get_msg(self, timeout=None):
        self.event.wait(timeout)
        return self.msg
