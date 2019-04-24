                 // Include simpletools header
#include <Servo.h>   

Servo servo1;

//Transistor 'Base' pin or input pin of motor driver ic to Arduino PWM Digital Pin 3
#define motorPinA 3
#define in2 5
#define in1 4
#define motorPinB 6
#define in3 7
#define in4 8

char incomingByte;
int Speed; //Variable to store Speed, by defaul 0 PWM
int flag;
int backward;
int forward;
int cutMotors;

void setup()
{
  pinMode(motorPinA, OUTPUT); 
  pinMode(motorPinB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  servo1.attach(9); //assigning servo pin
  Serial.begin(9600); //Init serial communication
  Serial.println(incomingByte);
}

void loop()
{ 
  if (Serial.available()) {
    incomingByte = Serial.read(); //grabs the character
    Speed = Serial.parseInt(); //grabs the integer
    if(Speed  == 255) {
      cutMotors = 0;
      analogWrite(motorPinA, LOW); //Stop motor A speed
      analogWrite(motorPinB, LOW); //Stop motor B speed
    }
    if(Speed > 255) {
      forward = Speed - 255; //calculates desired speed and direction
      if(incomingByte == 'F') {
        servo1.write(105);  //points servo forward
  
        analogWrite(motorPinA, forward); //Set motor A speed
        digitalWrite(in1, HIGH); // Set motor A forward
        digitalWrite(in2, LOW);
  
        analogWrite(motorPinB, forward); //Set motor B speed
        digitalWrite(in3, HIGH); // Set motor B forward
        digitalWrite(in4, LOW);
      }
      if(incomingByte == 'L') {
        servo1.write(140);
        
        analogWrite(motorPinA, forward); //Set motor A speed
        digitalWrite(in1, HIGH); // Set motor A backward
        digitalWrite(in2, LOW);
        
        analogWrite(motorPinB, forward); //Set motor B speed
        digitalWrite(in3, HIGH); // Set motor B backward
        digitalWrite(in4, LOW);
      }
      if(incomingByte == 'Y') {
        servo1.write(175);
        
        analogWrite(motorPinA, forward); //Set motor A speed
        digitalWrite(in1, HIGH); // Set motor A backward
        digitalWrite(in2, LOW);
        
        analogWrite(motorPinB, forward); //Set motor B speed
        digitalWrite(in3, HIGH); // Set motor B backward
        digitalWrite(in4, LOW);
      }
      if(incomingByte == 'R') {
        servo1.write(75);
        
        analogWrite(motorPinA, forward); //Set motor A speed
        digitalWrite(in1, HIGH); // Set motor A backward
        digitalWrite(in2, LOW);
        
        analogWrite(motorPinB, forward); //Set motor B speed
        digitalWrite(in3, HIGH); // Set motor B backward
        digitalWrite(in4, LOW);
      }
      if(incomingByte == 'X') {
        servo1.write(40);
        
        analogWrite(motorPinA, forward); //Set motor A speed
        digitalWrite(in1, HIGH); // Set motor A backward
        digitalWrite(in2, LOW);
        
        analogWrite(motorPinB, forward); //Set motor B speed
        digitalWrite(in3, HIGH); // Set motor B backward
        digitalWrite(in4, LOW);
      }
    }
    if(Speed < 255) {
      backward = Speed * -1;
      backward = backward + 255;
      if(incomingByte == 'F') {
        servo1.write(105);
  
        analogWrite(motorPinA, backward); //Set motor A speed
        digitalWrite(in1, LOW); // Set motor A backward
        digitalWrite(in2, HIGH);
  
        analogWrite(motorPinB, backward); //Set motor B speed
        digitalWrite(in3, LOW); // Set motor B backward
        digitalWrite(in4, HIGH);
      }
      if(incomingByte == 'L') {
        servo1.write(140);
        
        analogWrite(motorPinA, backward); //Set motor A speed
        digitalWrite(in1, LOW); // Set motor A backward
        digitalWrite(in2, HIGH);
        
        analogWrite(motorPinB, backward); //Set motor B speed
        digitalWrite(in3, LOW); // Set motor B backward
        digitalWrite(in4, HIGH);
      }
      if(incomingByte == 'Y') {
        servo1.write(175);
        
        analogWrite(motorPinA, backward); //Set motor A speed
        digitalWrite(in1, LOW); // Set motor A backward
        digitalWrite(in2, HIGH);
        
        analogWrite(motorPinB, backward); //Set motor B speed
        digitalWrite(in3, LOW); // Set motor B backward
        digitalWrite(in4, HIGH);
      }
      if(incomingByte == 'R') {
        servo1.write(75);
        
        analogWrite(motorPinA, backward); //Set motor A speed
        digitalWrite(in1, LOW); // Set motor A backward
        digitalWrite(in2, HIGH);
        
        analogWrite(motorPinB, backward); //Set motor B speed
        digitalWrite(in3, LOW); // Set motor B backward
        digitalWrite(in4, HIGH);
      }
      if(incomingByte == 'X') {
        servo1.write(40);
        
        analogWrite(motorPinA, backward); //Set motor A speed
        digitalWrite(in1, LOW); // Set motor A backward
        digitalWrite(in2, HIGH);
        
        analogWrite(motorPinB, backward); //Set motor B speed
        digitalWrite(in3, LOW); // Set motor B backward
        digitalWrite(in4, HIGH);
      }
    }
  }
}
