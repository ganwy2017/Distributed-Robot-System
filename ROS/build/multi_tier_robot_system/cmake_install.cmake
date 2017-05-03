# Install script for directory: /home/samuel/Documents/Multi-tier-Robot-System/ROS/src/multi_tier_robot_system

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/samuel/Documents/Multi-tier-Robot-System/ROS/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_tier_robot_system/msg" TYPE FILE FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/src/multi_tier_robot_system/msg/Drive.msg")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_tier_robot_system/cmake" TYPE FILE FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system/catkin_generated/installspace/multi_tier_robot_system-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/include/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/share/roseus/ros/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/share/common-lisp/ros/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/share/gennodejs/ros/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/lib/python2.7/dist-packages/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/devel/lib/python2.7/dist-packages/multi_tier_robot_system")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system/catkin_generated/installspace/multi_tier_robot_system.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_tier_robot_system/cmake" TYPE FILE FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system/catkin_generated/installspace/multi_tier_robot_system-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_tier_robot_system/cmake" TYPE FILE FILES
    "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system/catkin_generated/installspace/multi_tier_robot_systemConfig.cmake"
    "/home/samuel/Documents/Multi-tier-Robot-System/ROS/build/multi_tier_robot_system/catkin_generated/installspace/multi_tier_robot_systemConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/multi_tier_robot_system" TYPE FILE FILES "/home/samuel/Documents/Multi-tier-Robot-System/ROS/src/multi_tier_robot_system/package.xml")
endif()

