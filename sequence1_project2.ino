// Boop de boop I am an edit. smiley face

const int switchPin = 3;
const int ledPin = 13;
int switchState = 0;
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  setColor(255, 165, 0);
  delay(1000);
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if(switchState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RED_PIN, redValue);
  analogWrite(GREEN_PIN, greenValue);
  analogWrite(BLUE_PIN, blueValue);
}
