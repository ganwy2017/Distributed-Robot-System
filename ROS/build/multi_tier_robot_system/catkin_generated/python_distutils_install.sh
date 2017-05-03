#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/samuel/Documents/Multi-tier-Robot-System/ROS/src/multi_tier_robot_system"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/samuel/Documents/Multi-tier-Robot-System/ROS/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/samuel/Documents/Multi-tier-Robot-System/ROS/install/lib/python2.7/dist-packages:/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/samuel/Documents/Multi-tier-Robot-System/ROS/build" \
    "/usr/bin/python" \
    "/home/samuel/Documents/Multi-tier-Robot-System/ROS/src/multi_tier_robot_system/setup.py" \
    build --build-base "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/samuel/Documents/Multi-tier-Robot-System/ROS/install" --install-scripts="/home/samuel/Documents/Multi-tier-Robot-System/ROS/install/bin"
