ROS_ARDUINO_WIICHUCK
==============

General Info
--------------
This is a package for use with ROS (http://www.ros.org/). It was built using ROS Indigo and ROSSerial_Arduino on Ubuntu 14.04 and an Arduino Uno.

The purpose of this package is to read the values from a Wii Nunchuck controller using an Arduino, and to pass along the values as a ROS message.

It makes use of the WiiChuck.h library as copied from http://playground.arduino.cc/Main/WiiChuckClass.

Custom Message
--------------
This package includes a custom message type called WiiChuck which contains the following:
- uint8 joyX
- uint8 joyY
- bool buttonZ
- bool buttonC
- float32 accelX
- float32 accelY
- float32 accelZ

Usage
--------------
Edit the firmware/CMakeLists.txt to be the correct board and port for your application.
Build the firmware with 
	catkin_make ros_arduino_wiichuck_firmware_wiichuck
Upload the firmware with 
	catkin_make ros_arduino_wiichuck_firmware_wiichuck-upload

To see the output run the following in 3 terminals

```
roscore
```

```
rosrun rosserial_python serial_node.py /dev/ttyACM1
```

```
rostopic echo chuck
```
