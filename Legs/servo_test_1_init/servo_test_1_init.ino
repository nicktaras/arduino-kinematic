
/*
  Servo Test 1.

  Connect servo to ground, 3.3v and pin 12.
  Test script to move the servo rotation from 0 to 180 degrees continously back and forth.

  Author: Nicholas Taras
*/

#include <Servo.h>

Servo myservo; // create servo object to control a servo

int servoPosition = 10; // variable to read the value from the analog pin
int dir = 1; // 1 forwards // 0 backwards
int vel = 10; // velocity
int del = 50; // delay
int servoRange = 180; // range 

void setup() {
  
  Serial.begin(9600);
  
  myservo.attach(12); // attaches the servo on pin 9 to the servo object
  
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

 myservo.write(servoPosition); // update servo. 
   
 delay(del); // delay between actions.
 
 Serial.print(servoPosition); // print updated servo position.
 
}

