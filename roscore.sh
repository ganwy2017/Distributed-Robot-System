#!/bin/bash

ip=`ifconfig | grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1'`

ip="10.188.88.91"

master_uri="http://$ip:11311"

export ROS_MASTER_URI=$master_uri
export ROS_IP=$ip
export ROS_HOSTNAME=$ip

echo $ip

killall -9 roscore
killall -9 rosmaster
roscore
