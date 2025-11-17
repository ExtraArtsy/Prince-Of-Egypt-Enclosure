#include <Servo.h>

Servo plagueServo1;
Servo plagueServo2;

const int switchPin = 2;
int plagueSwitchState = 0;

void setup() {
  // put your setup code here, to run once:
  plagueServo1.attach(5);
  plagueServo2.attach(6);

  pinMode(switchPin, INPUT);

  plagueServo1.write(0);
  plagueServo2.write(0);
  Serial.begin(9600);
}

void loop() {
  plagueSwitchState = digitalRead(switchPin);
  // Coded so that the servos activate when the switch is no longer being pressed down on.
  if(plagueSwitchState == HIGH) {
    plagueServo1.write(0);
    plagueServo2.write(180);
  }
  else {
    plagueServo1.write(180);
    plagueServo2.write(0);

  }
  delay(50);

}
