/*
TO MAKE THE SERVO MOVE IN AN ANTICLOCKWISE-CLOCKWISE PATTERN, OR A CLOCKWISE-ANTICLOCKWISE PATTERN, WITH A SMOOTH OR STAGGERED MOTION
USING BASIC TRIGONOMETRIC FUNCTIONS.
*/

#include<Servo.h>
Servo myMotor;          //Making a servo controller object
void setup() {
  Serial.begin(9600);   //Initializing serial comm with baud-rate 9600 bps
  myMotor.attach(2);    //Attaching control line to pin 2 of Arduino Mega
  myMotor.write(90);    //Half-setting the servo motor, to the mid position
  callPattern(0);
}

void loop() {
  int iterator = 1;
  for(; iterator < 180; iterator++){
    callPattern(iterator);
    delay(500);
    //Serial.println(iterator);
    }
}

void callPattern(int iterator){
  //int angle = (int)180*sin(iterator);       CLOCKWISE-ANTICLOCKWISE COMPLETE ROTATIONS \____ ONLY IF THE MOTOR IS DIRECTLY WRITTEN INTO WITHOUT ANY CONDITIONS(ref. LINE 9)
  //int angle = (int)180*cos(iterator);       ANTICLOCKWISE-CLOCKWISE COMPLETE ROTATIONS /
  int angle = (int)180*tan(iterator);       //Moves in a sexy pattern.. 
  if(angle > 0)                             
    myMotor.write(angle);
   else{
     angle += -(2*angle);
     myMotor.write(angle);
    }
    //myMotor.write(angle);                   LINE 9
  Serial.println(angle);
  }
