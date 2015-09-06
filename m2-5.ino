int leftButton = 14;
int rightButton = 15;
int lastLeftButtonState = 0;
int lastRightButtonState = 0;

int currentPin = 2;
int goLeft = 1;

long previousMillis = 0;
int ledDelay = 1000;

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

        if (currentPin == 13)
        {
            goLeft = 0;
        }
        else if (currentPin == 2)
        {
            goLeft = 1;
        }

        digitalWrite(currentPin, HIGH);

        if (goLeft == 1)
        {
            digitalWrite(currentPin - 1, LOW);
            currentPin++;
        }
        else
        {
            digitalWrite(currentPin + 1, LOW);
            currentPin--;
        }

        digitalWrite(currentPin, LOW);
    }

    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH && ledDelay < 2000)
    {
        ledDelay *= 2;
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH && ledDelay > 2)
    {
        ledDelay /= 2;
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
    delay(1);
}

