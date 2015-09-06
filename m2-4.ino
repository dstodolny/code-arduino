int currentLed = 1;

int leftButton = 14;
int rightButton = 15;
int lastLeftButtonState = 0;
int lastRightButtonState = 0;

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
    
    int leftButtonState = digitalRead(leftButton);
    int rightButtonState = digitalRead(rightButton);

    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH && currentLed < 13)
    {
        currentLed++;
        digitalWrite(currentLed, HIGH);
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH && currentLed > 1)
    {
        digitalWrite(currentLed, LOW);
        currentLed--;
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
    delay(1);
}

