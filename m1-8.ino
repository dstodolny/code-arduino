#define MAX_BLINKS 10

int pinLED = 12;

void setup() {
    pinMode(pinLED, OUTPUT);
}

void loop() {
  int i = 0;
    while (1) {
        if (i < MAX_BLINKS) {
            ledBlink();
            i++;
        }
    }
}

void ledBlink() {
    digitalWrite(pinLED, HIGH);
    delay(500);
    digitalWrite(pinLED, LOW);
    delay(500);
}

