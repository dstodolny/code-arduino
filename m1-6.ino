int pinLED = 5;
int pushButton = 9;

void setup() {
    Serial.begin(9600);
    
    pinMode(pinLED, OUTPUT);
    pinMode(pushButton, INPUT);
}

void loop() {
    int buttonState = digitalRead(pushButton);

    Serial.println(buttonState);

    if (buttonState) {
        ledBlink();
    }
    
    delay(1);
}

void ledBlink() {
    digitalWrite(pinLED, HIGH);
    delay(20);
    digitalWrite(pinLED, LOW);
    delay(200);
}

