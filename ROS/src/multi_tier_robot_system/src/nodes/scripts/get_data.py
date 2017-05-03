#!/usr/bin/env python

import threading


class GetData(object):

    def __init__(self):
        self._event = threading.Event()
        self._msg = None

    def __call__(self, msg):
        self._msg = msg
        self._event.set()

    def get_msg(self, timeout=None):
        self._event.wait(timeout)
        return self._msg
