#include <Servo.h>          //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
                
int angle = 0;    
 
void setup() 
{ 
  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
  servo_test.write(90);      // Sets serov to mid-point
} 
  
void loop() 
{ 
  //EVERY TIME LOOP IS CALLED, ANGLE WILL START FROM 0, WHICH WILL RESET THE SERVO.
  for(angle = 0; angle < 150; angle += 1)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
                                             //THIS WILL SET THE SERVO
    delay(5);                               //This will be smoother for this delay
    //delay(50);                            This motor will stagger for this delay
    Serial.println(angle);
  } 
  delay(1000);

  for(angle = servo_test.read(); angle < servo_test.read() + 30; angle+=1){  //angle relative to the current angle(clockwise) for positive voltage
    servo_test.write(angle);
    delay(9); 
   }

   delay(1000);
  for(angle = 180; angle>=1; angle-=5)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(5);
    Serial.println(angle);                       
  } 

    delay(1000);
}
