/* meArm R.A.T test - Team Design Project Dec 2021
 * Test applying Nick Moriarty's Inverse Kinematics solver
 * to Phenoptix' meArm robotic arm, to walk a defined path.
 *
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Gripper
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Orange
 *     10             Orange
 *      9                     Orange
 *      6                               Orange
*/

#include <Servo.h>
#include "ik.h"
#include "meArm.h"

Servo base, claw, up_down, front_back;
int angle = 0;

//digital pins
int basePin = 9;//red wire left-right
int shoulderPin = 6; //orange wire up/down shoulder
int elbowPin = 7;//front/back blue wire elbow
int gripperPin = 8;//purple wire, gripper/claw


//analogue pins
int xdirPin = 1;
int ydirPin = 0;
int zdirPin = 3;
int gdirPin = 2;

meArm arm;

void setup() 
{ 
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
}

void loop()
{
  float dx = map(analogRead(xdirPin), 0, 1023, -5.0, 5.0);
  float dy = map(analogRead(ydirPin), 0, 1023, 5.0, -5.0);
  float dz = map(analogRead(zdirPin), 0, 1023, 5.0, -5.0);
  float dg = map(analogRead(gdirPin), 0, 1023, 5.0, -5.0);
  if (abs(dx) < 1.5) dx = 0;
  if (abs(dy) < 1.5) dy = 0;
  if (abs(dz) < 1.5) dz = 0;
  if(abs(dg) < 1.5) dg = 0;

  if (!(dx == 0 && dy == 0 && dz == 0))
    arm.goDirectlyTo(arm.getX() + (dx * 0.66f), arm.getY() + (dy * 0.66f), arm.getZ() + (dz * 0.66f));

  if (dg < -3.0)
  {
    Serial.print("claw is closing");
      arm.closeGripper();
  }
  else if (dg > 3.0)
    arm.openGripper();  
    
  delay(50);
}

void CalibrateServos()
{
  
}