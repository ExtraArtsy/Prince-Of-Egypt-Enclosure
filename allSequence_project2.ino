// The Prince of Egypt
// Team Name: The Plague Doctors
// Team Members: Nova Cano, Paulina Mroue
// Description: In this program, we have all five interactions, with LEDs, Servos, and switches to present the interactions.

// Black wires are for ground
// Red wires are for power
// Yellow wires are for servos
// Green wires are for LEDs (LED wires go into the analog pins)
// Blue wires are for switches

// Code is ordered by the sequence of events in the enclosure.

#include <Servo.h>

// VARIABLES
// For Sequence 1: A switch, switch state, and two LED pins so that a yellow light can be made
const int switchPin = 2;
const int ledPinRed = A0;
const int ledPinGreen = A1;
int switchState = 0;

// For Sequence 2: A switch, switch state, and two 180 servos
Servo plagueServo1;
Servo plagueServo2;
const int plagueSwitchPin = 3;
int plagueSwitchState = 0;

// For Sequence 3: A switch, switch state, and one 180 servo. There are also bool variables to check if the servo was activated.
Servo handServo;
const int handSwitchPin = 4;
const int handServoPos = 0;
int handSwitchState = 0;
int previousHandSwitchState = 90;
bool servoTurned = false; 

// For Sequence 4: A switch, switch state, and two LEDs so a purple light can be made. There is also a bool variable to check if the previous sequence was activated.
bool handFallen = false;
const int redledPin = A2;
const int blueledPin = A3;
const int bedswitchPin = 5;

// For Sequence 5: A switch, switch state, and two 360 Servos
Servo seaServo1;
Servo seaServo2;
const int seaSwitchPin = 6;
int seaSwitchState = 0;

// SETUP
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

// LOOP
void loop() {
  
  // For Sequence 1: A switch connected to Moses's staff activates to light up an LED behind him and Ramses.
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

  // For Sequence 2: A switch is deactivated in this case so that the frogs from the 10 plagues swoop into the scene when the statue's head falls.
  plagueSwitchState = digitalRead(plagueSwitchPin);
  // Coded so that the servos activate when the switch is no longer being pressed down on.
  if(plagueSwitchState == LOW) {
    plagueServo1.write(120);
    plagueServo2.write(180);
  }
  else {
    plagueServo1.write(0);
    plagueServo2.write(110);
  }

  // For Sequence 3: A switch is pressed to activate a 180 servo that drops Ramses' son's hand to the ground. Once the switch activates, the servo cannot turn back afterwards.
  handSwitchState = digitalRead(handSwitchPin);
  Serial.println(handSwitchState);
  if(handSwitchState != previousHandSwitchState) {
    if(handSwitchState == HIGH) {
      Serial.println("Switch activated");
      handServo.write(90);
      servoTurned = true;
      handFallen = true;    
      // Sequence 4 cannot work properly until sequence 3 activates. The hand falling triggers the purple LED to activate.
    }
  }

  // For Sequence 4: A switch is pressed to deactivate the purple LED above the scene. This sequence only works after sequence 3 is activated; otherwise, the LED stays off.
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

  // For Sequence 5: A switch is pressed to activate 360 Servos that split open the Red Sea.
  seaSwitchState = digitalRead(seaSwitchPin);
  if(seaSwitchState == LOW) {
    seaServo1.write(90);
    seaServo2.write(90);
  }
  else {
    seaServo1.write(180);
    seaServo2.write(0);
  }
  delay(50);

}
