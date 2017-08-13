#ifndef MyServo_h
#define MyServo_h

#include "Arduino.h"
#include <Servo.h>
class MyServo{
  public:
    Servo motor;
    MyServo(int pinNo);
    void setSmooth(int angle);
    void setSmooth(int startAngle, int endAngle);
    void setStaggered(int startAngle, int endAngle, int delayMicroSeconds, int stagger);             //Overloading the function for different functionalities
    void setStaggered(int angle, int delayMicroSeconds, int stagger);                               //---"-------------------"-------------------"----------
    
    void resetSmooth(int angle);
    void resetSmooth(int startAngle, int endAngle);                                                 //Overloading the function for different functionalities
    void resetStaggered(int angle, int delayMicroSeconds, int stagger);                  
    void resetStaggered(int startAngle, int endAngle, int delayMicroSeconds, int stagger);          //---"-------------------"-------------------"----------
                             

    void halfSet();                                                                               //Function for halfSetting

};

#endif