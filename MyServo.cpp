#include "MyServo.h"
#include <Servo.h>
int ang = 0;
Servo motor;
int _pin=0;
MyServo::MyServo(int pin){
  pinMode(pin, OUTPUT);     //Output the pin to the user
  _pin = pin;              //This means that "pin" is a PRIVATE VARIABLE
}

void MyServo::setSmooth(int angle){
   for(ang = 0; ang < angle; ang += 1){        // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                         //command to rotate the servo to the specified angle
    delay(10);                               //This will be smoother for this delay
  }
}

void MyServo::setSmooth(int startAngle, int endAngle){
   for(ang = startAngle; ang < endAngle; ang += 1){    // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                                 //command to rotate the servo to the specified angle
    delay(10);                                       //This will be smoother for this delay
  }
}

void MyServo::setStaggered(int startAngle, int endAngle, int delayMicroSeconds, int stagger){
   if((stagger<0||stagger>180) || (delayMicroSeconds<250 || delayMicroSeconds>2000))
    return;
   
   for(ang = startAngle; ang < endAngle; ang += stagger){    // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                                       //command to rotate the servo to the specified angle
    delay(delayMicroSeconds);                              //This will be smoother for this delay
  }
}

void MyServo::setStaggered(int angle, int delayMicroSeconds, int stagger){
   if((stagger<0||stagger>180) || (delayMicroSeconds<250 || delayMicroSeconds>2000))
    return;
   
   for(ang = 0; ang < angle; ang += stagger){           // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                                  //command to rotate the servo to the specified angle
    delay(delayMicroSeconds);                         //This will be smoother for this delay
  }
}


void MyServo::resetSmooth(int angle){
   for(ang = 180; ang > angle; ang -= 1){        // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                           //command to rotate the servo to the specified angle
    delay(10);                                 //This will be smoother for this delay
  }
}

void MyServo::resetSmooth(int startAngle, int endAngle){
   for(ang = startAngle; ang > endAngle; ang -= 1){    // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                            //command to rotate the servo to the specified angle
    delay(10);                                       //This will be smoother for this delay
  }
}

void MyServo::resetStaggered(int startAngle, int endAngle, int delayMicroSeconds, int stagger){
  if((stagger<0||stagger>180) || (delayMicroSeconds<250 || delayMicroSeconds>2000))
   return;
  
   for(ang = startAngle; ang > endAngle; ang -= stagger){    // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                                  //command to rotate the servo to the specified angle
    delay(delayMicroSeconds);                              //This will be smoother for this delay
  }
}

void MyServo::resetStaggered(int angle, int delayMicroSeconds, int stagger){
  if((stagger<0||stagger>180) || (delayMicroSeconds<250 || delayMicroSeconds>2000))
   return;
  
   for(ang = 180; ang > angle; ang -= stagger){              // command to move from 0 degrees to 180 degrees                                  
    motor.write(ang);                                  //command to rotate the servo to the specified angle
    delay(delayMicroSeconds);                              //This will be smoother for this delay
  }
}

void MyServo::halfSet(){
  motor.write(90);
}
