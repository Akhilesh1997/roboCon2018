#include<Servo.h>
Servo motor;
void setup() {
 Serial.begin(9600);
 motor.attach(9);
 motor.write(90);
}

void loop() {
  int hand = 0;
  for(; hand < 180; hand++){
    tickTock(hand);
    delay(10);
  }

  for(; hand > 0; hand--){
    tickTock(hand);
    delay(10);
  }
}

void tickTock(int hand){
  motor.write(hand);
  if(hand%10 == 0)
    delay(1000);
  }
