int leftButton = 14;
int rightButton = 15;
int lastLeftButtonState = 0;
int lastRightButtonState = 0;

int currentPin;
int state = LOW;

unsigned long previousMillis = 0;
unsigned long brightnessMillis = 0;

int ledDelay;
int brightnessDelay = 100;
int lighten = 1;

int onDelay = 1;
int period = 5;

void setup()
{   
    Serial.begin(9600);
    
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

    if(currentMillis - brightnessMillis > brightnessDelay) {
        brightnessMillis = currentMillis;
        
        Serial.println(onDelay);
        
        if (lighten == 1)
        {
            onDelay++;
            if (onDelay > 5)
            {
                lighten = 0;
                onDelay--;
            }
        }
        else
        {
            onDelay--;
            if (onDelay < 0)
            {
                lighten = 1;
                onDelay++;
            }
        }
    }

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

    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH && brightnessDelay > 50)
    {
        brightnessDelay -= 50;
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH && brightnessDelay < 500)
    {
        brightnessDelay += 50;
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
}

