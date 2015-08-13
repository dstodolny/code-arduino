int pinLED = 12;
int dotLength = 100;

void setup() {
    pinMode(pinLED, OUTPUT);
}

void loop() {
    // Say "Dominik"
    dash(); dot(); dot(); pauseChar();
    dash(); dash(); dash(); pauseChar();
    dash(); dash(); pauseChar();
    dot(); dot(); pauseChar();
    dash(); dot(); pauseChar();
    dot(); dot(); pauseChar();
    dash(); dot(); dash(); pauseChar();
    pauseWord();
}

void dot() {
    digitalWrite(pinLED, HIGH);
    delay(dotLength);
    digitalWrite(pinLED, LOW);
    delay(dotLength);
}

void dash() {
    digitalWrite(pinLED, HIGH);
    delay(dotLength * 3);
    digitalWrite(pinLED, LOW);
    delay(dotLength);
}

void pauseChar() {
    delay(dotLength * 2);
}

void pauseWord() {
    delay(dotLength * 6);
}
