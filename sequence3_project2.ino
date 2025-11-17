#include <Servo.h>

Servo handServo;
const int switchPin = 4;
const int servoPos = 0;
int handSwitchState = 0;
int previousHandSwitchState = 90;
bool servoTurned = false; 

void setup() {
  handServo.attach(11);
  pinMode(switchPin, INPUT);
   handServo.write(0);
  Serial.begin(9600);
}

void loop() {
  handSwitchState = digitalRead(switchPin);
  Serial.println(handSwitchState);
  if(handSwitchState != previousHandSwitchState) {
    if(handSwitchState == HIGH) {
    handServo.write(90);
    servoTurned = true;
    }
  }
}
