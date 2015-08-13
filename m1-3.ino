int pinLED = 2;

void setup() {
  while(pinLED <= 10) {
    pinMode(pinLED, OUTPUT);
    pinLED++;
  }
}

void loop() {
  pinLED = 2;
  while(pinLED <= 10) {
    digitalWrite(pinLED, HIGH);
    delay(50);
    digitalWrite(pinLED, LOW);
    pinLED++;
  }
}
