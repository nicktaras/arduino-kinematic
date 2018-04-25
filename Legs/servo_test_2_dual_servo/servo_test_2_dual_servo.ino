
/*
  Servo Test 2.

  Connect servo A to ground, 3.3v and pin 12.
  Connect servo B to ground, 3.3v and pin 11.
  
  Test script to move two servos rotation from 0 to 180 degrees continously back and forth in sync.

  Author: Nicholas Taras
*/

#include <Servo.h>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

Servo myservoA; // create servo object to control a servo
Servo myservoB; // create servo object to control a servo

int servoAPin = 11; // variable to read the value from the analog pin
int servoBPin = 12; // variable to read the value from the analog pin
int dir = 1; // 1 forwards // 0 backwards
int vel = 10; // velocity
int del = 50; // delay
int servoRange = 180; // range 
int servoPosition = 0;

void setup() {
  
  Serial.begin(9600);
  
  myservoA.attach(servoAPin); // attaches the servo on pin 9 to the servo object
  myservoB.attach(servoBPin); // attaches the servo on pin 9 to the servo object
  
}

void loop() {
  
 // 0 - 180 range

 // update servo direction
 
 if(servoPosition >= (servoRange - vel)){
  
  dir = 0;
  
 } else if(servoPosition <= (0 + vel)) {
  
  dir = 1;
  
 }

 // update move position

 if(dir == 1){
  
    servoPosition += vel;
    
 }

 if(dir == 0){
  
    servoPosition -= vel;
    
 }

 myservoA.write(servoPosition); // update servo. 
 myservoB.write(servoPosition); // update servo. 
   
 delay(del); // delay between actions.
 
 Serial.print(servoPosition); // print updated servo position.
 
}

