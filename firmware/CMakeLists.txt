cmake_minimum_required(VERSION 2.8.3)

include_directories(${ROS_LIB_DIR})

# Remove this is using an Arduino without natve USB (eg, other then Leonardo)
add_definitions(-DUSB_CON)

generate_arduino_firmware(wiichuck
	SRCS wiichuck.cpp ${ROS_LIB_DIR}/time.cpp
	BOARD uno
	PORT /dev/ttyACM1
)