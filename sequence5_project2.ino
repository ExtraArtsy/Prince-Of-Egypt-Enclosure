#include <Servo.h>

Servo seaServo1;
Servo seaServo2;

const int seaSwitchPin = 2;

const int servo1Pos1 = 0;
const int servo1Pos2 = 90;
const int servo2Pos1 = 180;
const int servo2Pos2 = 90;

int seaSwitchState = 0;

void setup() {
  // put your setup code here, to run once:
  seaServo1.attach(9);
  seaServo2.attach(10);

  pinMode(seaSwitchPin, INPUT_PULLUP);

  seaServo1.write(servo1Pos1);
  seaServo2.write(servo2Pos1);
}

void loop() {
  // put your main code here, to run repeatedly:
  seaSwitchState = digitalRead(seaSwitchPin);
  if(seaSwitchState == LOW) {
    seaServo1.write(servo1Pos2);
    seaServo2.write(servo2Pos2);
  }
  else {
    seaServo1.write(servo1Pos1);
    seaServo2.write(servo2Pos1);
  }
  delay(50);

}
