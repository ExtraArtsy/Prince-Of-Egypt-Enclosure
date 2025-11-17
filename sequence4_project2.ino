const int redledPin = 8;
const int bedswitchPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(redledPin, OUTPUT);
  pinMode(bedswitchPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int bedswitchState = digitalRead(bedswitchPin);
  
  if(bedswitchState == HIGH) {
    digitalWrite(redledPin, LOW);
  }
  else {
    digitalWrite(redledPin, HIGH);
  }

}
