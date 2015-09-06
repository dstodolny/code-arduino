int leftButton = 14;
int rightButton = 15;
int lastLeftButtonState = 0;
int lastRightButtonState = 0;

int currentPin;
int state = LOW;

long previousMillis = 0;
int ledDelay;

int onDelay = 1;
int period = 5;

void setup()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        pinMode(currentPin, OUTPUT);
    }
    pinMode(leftButton, INPUT);
    pinMode(rightButton, INPUT);
}

void loop()
{
    unsigned long currentMillis = millis();
    int leftButtonState = digitalRead(leftButton);
    int rightButtonState = digitalRead(rightButton);

    if (currentMillis - previousMillis > ledDelay) {
        previousMillis = currentMillis;

        if (state == LOW && onDelay > 0)
        {
            state = HIGH;
            ledDelay = onDelay;
        }
        else
        {
            state = LOW;
            ledDelay = period - onDelay;
        }

        for (currentPin = 2; currentPin <= 13; currentPin++)
        {
            digitalWrite(currentPin, state);
        }
    }

    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH && onDelay > 0)
    {
        onDelay--;
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH && onDelay < 5)
    {
        onDelay++;
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
    delay(1);
}

