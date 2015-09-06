int leftButton = 14;
int rightButton = 15;
int lastLeftButtonState = 0;
int lastRightButtonState = 0;

int currentPin = 2;
int goLeft = 1;

long previousMillis = 0;
int ledDelay = 1000;

int program = 1;
int programSpeed = 1;

// equalizer
int barHeight = random(3, 13);

// police
int state = LOW;

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

    if (currentMillis - previousMillis > ledDelay)
    {
        previousMillis = currentMillis;
        
        Serial.println(programSpeed);
        switch(programSpeed % 5)
        {
            case 1:
                ledDelay = 400;
                break;
            case 2:
               ledDelay = 200;
               break;
            case 3:
               ledDelay = 100;
               break;
            case 4:
               ledDelay = 50;
               break;
            case 0:
               ledDelay = 25;
               break;
        }

        switch(program % 4)
        {
            case 1:
                knightRider();
                break;
            case 2:
                randomLed();
                break;
            case 3:
                equalizer();
                break;
            case 0:
                police();
                break;
        }
        
    }

    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH)
    {
        program++;
        ledReset();
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH)
    {
        programSpeed++;
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
    delay(1);
}

void ledReset()
{
    for (int i = 2; i <= 13; i++)
    {
        digitalWrite(i, LOW);
    }
    currentPin = 2;
}

void knightRider()
{
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

void randomLed()
{
    digitalWrite(random(2, 13), HIGH);
    digitalWrite(random(2, 13), LOW);
}

void equalizer()
{   
    if (goLeft == 1)
    {
        digitalWrite(currentPin, HIGH);
        
        if (currentPin > barHeight)
        {
            goLeft = 0;
        }
        else
        {
            currentPin++;
        }
    }
    else
    {
        digitalWrite(currentPin, LOW);

        if (currentPin < 2)
        {
            goLeft = 1;
            barHeight = random(3, 13);
            
        }
        else
        {
            currentPin--;
        }
    }
}

void police()
{
    for(int i = 2; i < 8; i++)
    {
        digitalWrite(i, state);
    }

    if (state == LOW)
    {
        state = HIGH;
    }
    else
    {
        state = LOW;
    }
    
    for(int i = 8; i <= 13; i++)
    {
        digitalWrite(i, state);
    }
}

