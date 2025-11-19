// Black wires are for ground
// Red wires are for power
// Yellow wires are for servos
// Green wires are for LEDs (LED wires go into the analog pins)
// Blue wires are for switches

// Code is ordered by the sequence of events in the enclosure

#include <Servo.h>

// For Sequence 1:
const int switchPin = 2;
const int ledPinRed = A0;
const int ledPinGreen = A1;
int switchState = 0;

// For Sequence 2:
Servo plagueServo1;
Servo plagueServo2;
const int plagueSwitchPin = 3;
int plagueSwitchState = 0;

// For Sequence 3:
Servo handServo;
const int handSwitchPin = 4;
const int handServoPos = 0;
int handSwitchState = 0;
int previousHandSwitchState = 90;
bool servoTurned = false; 

// For Sequence 4:
bool handFallen = false;
const int redledPin = A2;
const int blueledPin = A3;
const int bedswitchPin = 5;

// For Sequence 5:
Servo seaServo1;
Servo seaServo2;
const int seaSwitchPin = 6;
int seaSwitchState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // For debugging

  // For Sequence 1:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(switchPin, INPUT);

  // For Sequence 2:
  plagueServo1.attach(9) ;
  plagueServo2.attach(10);
  pinMode(plagueSwitchPin, INPUT);
  plagueServo1.write(0);
  plagueServo2.write(0);

  // For Sequence 3:
  handServo.attach(11);
  pinMode(handSwitchPin, INPUT);
  handServo.write(0);
  Serial.println("Servo ready");

  // For Sequence 4:
  pinMode(redledPin, OUTPUT);
  pinMode(blueledPin, OUTPUT);
  pinMode(bedswitchPin, INPUT);

  // For Sequence 5:
  seaServo1.attach(12);
  seaServo2.attach(13);
  pinMode(seaSwitchPin, INPUT_PULLUP);
  seaServo1.write(0);
  seaServo2.write(180);
}

void loop() {
  
  // For Sequence 1:
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if(switchState == HIGH) {
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinGreen, HIGH);
    analogWrite(ledPinGreen, 135);
    analogWrite(ledPinRed, 155);
  }
  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, LOW);
  }

  // For Sequence 2:
  plagueSwitchState = digitalRead(plagueSwitchPin);
  // Coded so that the servos activate when the switch is no longer being pressed down on.
  if(plagueSwitchState == LOW) {
    plagueServo1.write(0);
    plagueServo2.write(180);
  }
  else {
    plagueServo1.write(180);
    plagueServo2.write(0);
  }

  // For Sequence 3:
  handSwitchState = digitalRead(handSwitchPin);
  Serial.println(handSwitchState);
  if(handSwitchState != previousHandSwitchState) {
    if(handSwitchState == HIGH) {
      Serial.println("Switch activated");
      handServo.write(90);
      servoTurned = true;
      handFallen = true;    // Sequence 4 cannot work properly until sequence 3 activates. The hand falling triggers the purple LED to activate.
    }
  }

  // For Sequence 4:
  if(handFallen) {
    int bedswitchState = digitalRead(bedswitchPin);
      if(bedswitchState == HIGH) {
        digitalWrite(redledPin, LOW);
        digitalWrite(blueledPin, LOW);
      }
      else {
        digitalWrite(redledPin, HIGH);
        digitalWrite(blueledPin, HIGH);
        analogWrite(redledPin, 255);
        analogWrite(blueledPin, 255);
      }
  }

  // For Sequence 5:
  seaSwitchState = digitalRead(seaSwitchPin);
  if(seaSwitchState == LOW) {
    seaServo1.write(90);
    seaServo2.write(90);
  }
  else {
    seaServo1.write(0);
    seaServo2.write(180);
  }
  delay(50);

}
