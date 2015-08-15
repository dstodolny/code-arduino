#define MAX_BLINKS 10

int pinLED = 12;

void setup() {
    pinMode(pinLED, OUTPUT);
}

void loop() {
  for (int i = 0; i < MAX_BLINKS; i++) {
      ledBlink();
  }
  delay(2500);
}

void ledBlink() {
    digitalWrite(pinLED, HIGH);
    delay(500);
    digitalWrite(pinLED, LOW);
    delay(500);
}

