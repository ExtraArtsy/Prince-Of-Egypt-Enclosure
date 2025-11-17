const int switchPin = 3;
const int ledPinRed = 13;
const int ledPinGreen = 12;
int switchState = 0;
void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(50);
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

}
