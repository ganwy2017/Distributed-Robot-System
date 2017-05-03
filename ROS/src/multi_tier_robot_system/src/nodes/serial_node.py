#!/usr/bin/env python

import rospy
from serial import SerialException
from rosserial_python import SerialClient
from rosserial_python import RosSerialServer
from time import sleep
import multiprocessing
import sys


def main(argv):
	if len(argv) == 2:
		port_name = rospy.get_param("~port", argv[1])
	else:
		print("Usage: python serial_node.py <port_name>")
		return 1

	rospy.init_node("Pi_Node", log_level=rospy.DEBUG)
	rospy.loginfo("ROS serial python node initialised")
	baud = int(rospy.get_param("~baud", "57600"))
	tcp_portnum = int(rospy.get_param("/rosserial_embeddedlinux/tcp_port", "11411"))
	fork_server = rospy.get_param('/rosserial_embeddedlinux/fork_server', False)

	if port_name == "tcp":
		server = RossSerialServer(tcp_portnm, fork_Server)
		rospy.loginfo("Waiting for socket connections on port %d" % tcp_portnum)
		try:
			server.losten()
		except KeyboardInterupt:
			rospy.loginfo()
		finally: 
			rospy.loginfo("Shutting down")
			for process in multiprocessing.active_children():
				rospy.lofinfo("Shutting down process %r", process)
				process.terminate()
				process.join()
			rospy.loginfo("End")
	else:
		while not rospy.is_shutdown():
			rospy.loginfo("Connecting to %s at %d baud" % (port_name, baud))
			try:
				client = SerialClient(port_name, baud)
				client.run()
			except SerialException:
				sleep(1)
				continue
			except OSError:
				sleep(1)
				continue

if __name__=="__main__":
	main(sys.argv)
