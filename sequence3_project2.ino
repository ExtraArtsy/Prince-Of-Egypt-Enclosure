#include <Servo.h>
Servo myservo;

const int switchPin = 7;
const int servoPin = 9;
const int ledPin = 13:

int switchState = 0;
bool activated = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if(switchState == HIGH && !activated) {
    myservo.write(90);
    activated = true;
    delay(1000);
  }

}
