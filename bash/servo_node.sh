#!/bin/bash

host_ip=$1
local_ip=`ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1'`

master_uri="http://$host_ip:11311"

export ROS_MASTER_URI=$master_uri
export ROS_IP=$local_ip
export ROS_HOSTNAME=$local_ip

cd ../catkin/src/distributed_robot_system/src/nodes
sudo pigpiod
python servo_node.py



