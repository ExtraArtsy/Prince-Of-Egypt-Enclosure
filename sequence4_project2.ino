const int redledPin = 13;
const int blueledPin = 12;
const int bedswitchPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redledPin, OUTPUT);
  pinMode(blueledPin, OUTPUT);
  pinMode(bedswitchPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
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
