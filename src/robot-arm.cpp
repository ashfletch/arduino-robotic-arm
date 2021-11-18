#include <servo.h>

Servo middle,left,right,claw; // creates 4 "servo objects"

void setup()
{
    Serial.begin(9600);
    middle.attach(11); // attaches the servo
}