#include "meArm.h"
#include <Servo.h>

meArm arm;

void setup() {
  arm.begin(11, 10, 9, 6);
  arm.openGripper();
}

void loop() {
  //Go up and left to grab something
  arm.gotoPoint(-80,100,140); 
  arm.closeGripper();
  //Go down, forward and right to drop it
  arm.gotoPoint(70,200,10);
  arm.openGripper();
  //Back to start position
  arm.gotoPoint(0,100,50);
}