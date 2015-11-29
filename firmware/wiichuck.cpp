#include <Arduino.h>
#include <ros.h>
#include <ros_arduino_wiichuck/WiiChuck.h>


#include "WiiChuck.h"

WiiChuck chuck = WiiChuck();

ros::NodeHandle nh;

ros_arduino_wiichuck::WiiChuck chuck_msg;
ros::Publisher chuckPub("chuck", &chuck_msg);

char hello[13] = "hello world!";

void setup() {
	nh.initNode();
	nh.advertise(chuckPub);

	chuck.begin();
	chuck.update();
}

void loop() {
	delay(20);
	chuck.update();

	chuck_msg.joyX = chuck.readJoyX();
	chuck_msg.joyY = chuck.readJoyY();
	chuck_msg.buttonZ = chuck.buttonZ;
	chuck_msg.buttonC = chuck.buttonC;
	chuck_msg.accelX = chuck.readAccelX();
	chuck_msg.accelY = chuck.readAccelY();
	chuck_msg.accelZ = chuck.readAccelZ();
	chuckPub.publish(&chuck_msg);
	nh.spinOnce();
	delay(100);
}