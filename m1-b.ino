const int ledPin = 13;

int ledState = LOW;
long int previousStateMillis = 0;
long int previousLedMillis = 0;
int stateInterval = 1000;
int ledInterval = 1;

int ledBlink = 1;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    unsigned long currentMillis = millis();

    if (ledBlink == 1)
    {
        if (currentMillis - previousLedMillis > ledInterval)
        {
            previousLedMillis = currentMillis;
    
            if (ledState == LOW)
            {
                ledState = HIGH;
            }
            else
            {
                ledState = LOW;
            }
        }
        digitalWrite(ledPin, ledState);
    }
    else
    {
        digitalWrite(ledPin, HIGH);
    }

    
    if (currentMillis - previousStateMillis > stateInterval)
    {
        previousStateMillis = currentMillis;
        
        if (ledBlink == 1)
        {
            ledBlink = 0;
        }
        else
        {
            ledBlink = 1;
        }
    }
}
