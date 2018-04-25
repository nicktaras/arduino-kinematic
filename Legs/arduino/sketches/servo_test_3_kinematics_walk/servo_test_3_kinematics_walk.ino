
/*
  Servo Test 3.

  Connect servo A to ground, 3.3v and pin 12.
  Connect servo B to ground, 3.3v and pin 11.
  servor range is 180.
  
  Test script to move two servos in a walking motion.

  Author: Nicholas Taras
*/

#include <Servo.h>   
#include <math.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             

Servo myservoA; // create servo object to control a servo
Servo myservoB; // create servo object to control a servo

int servoAPin = 11; // variable to read the value from the analog pin
int servoBPin = 12; // variable to read the value from the analog pin

// need to be updated
int dir = 1; // 1 forwards // 0 backwards
int vel = 1; // velocity
int del = 200; // delay
int cycle = 0; // angle of cycle

int servoPositionA = 0; // Hip
int servoPositionB = 0; // Knee

int thighRange = 45;
int thighBase = 85;
int calfRange = 45;
int calfOffset = -1.65;

void setup() {
  
  Serial.begin(9600);
  
  myservoA.attach(servoAPin); // attaches the servo on pin 12 to the servo object
  myservoB.attach(servoBPin); // attaches the servo on pin 11 to the servo object
  
}

int walk(int servoPositionA, int servoPositionB, int cycle) {

  int angleA = sin(cycle) * thighRange + thighBase;
  int angleB = sin(cycle + calfOffset) * calfRange + calfRange;

  Serial.print("Angle A: ");
  Serial.print(angleA);

  Serial.println("Angle B: ");
  Serial.print(angleB);

  servoPositionA = angleA;
  servoPositionB = angleB;

  myservoA.write(servoPositionA);
  myservoB.write(servoPositionB);

}

void loop() {

  walk(servoPositionA, servoPositionB, cycle);
   
  cycle += vel;
   
  delay(del); // delay between actions.
 
  Serial.print(servoPositionA); // print updated servo position.
  Serial.print(servoPositionB); // print updated servo position.
 
}
