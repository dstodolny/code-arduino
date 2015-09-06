#define LEFTBUTTON 14
#define RIGHTBUTTON 15

#include <stdbool.h>

int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int maxCount = 1023;
int number = 0;

unsigned long previousMillis = 0;
unsigned long incrementPreviousMillis = 0;
unsigned long buttonPreviousMillis = 0;
const unsigned long buttonSampleIntervalMs = 25;
const unsigned long incrementIntervalMs = 100;

byte longButtonPressCountMax = 40;  // 40 * 25 = 1000 ms
byte longLeftButtonPressCount = 0;
byte longRightButtonPressCount = 0;

byte previousLeftButtonState = LOW;
byte previousRightButtonState = LOW;

void setup()
{
    pinMode(LEFTBUTTON, INPUT);
    pinMode(RIGHTBUTTON, INPUT);
    
    for (int i = 0; i < 10; i++)
    {
        pinMode(ledPin[i], OUTPUT);
    }
}

void loop()
{
    if (millis() - buttonPreviousMillis >= buttonSampleIntervalMs)
    {
        buttonPreviousMillis = millis();

        byte currentLeftButtonState = digitalRead(LEFTBUTTON);
        byte currentRightButtonState = digitalRead(RIGHTBUTTON);

        if ((previousLeftButtonState == LOW) && (currentLeftButtonState == HIGH))
        {
            longLeftButtonPressCount = 0;
        }
        else if ((previousLeftButtonState == HIGH) && (currentLeftButtonState == LOW))
        {
            if (longLeftButtonPressCount < longButtonPressCountMax)
            {
                shortButtonPress(1); // add
            }
        }
        else if (currentLeftButtonState == HIGH)
        {
            longLeftButtonPressCount++;

            if (longLeftButtonPressCount >= longButtonPressCountMax)
            {
                longButtonPress(1); // add
            }
        }

        if ((previousRightButtonState == LOW) && (currentRightButtonState == HIGH))
        {
            longRightButtonPressCount = 0;
        }
        else if ((previousRightButtonState == HIGH) && (currentRightButtonState == LOW))
        {
            if (longRightButtonPressCount < longButtonPressCountMax)
            {
                shortButtonPress(0); // subtract
            }
        }
        else if (currentRightButtonState == HIGH)
        {
            longRightButtonPressCount++;

            if (longRightButtonPressCount >= longButtonPressCountMax)
            {
                longButtonPress(0); // subtract
            }
        }

        previousLeftButtonState = currentLeftButtonState;
        previousRightButtonState = currentRightButtonState;
    }

    displayBinary(number);
}

void shortButtonPress(int action)
{
    commitAction(action);
}

void longButtonPress(int action)
{
    if (millis() - incrementPreviousMillis >= incrementIntervalMs)
    {
        incrementPreviousMillis = millis();
        commitAction(action);
    }
}

void commitAction(int action)
{
    if (action == 1 && number < maxCount)
    {
        number++;
    }
    else if (action == 0 && number > 0)
    {
        number--;
    }
}

void displayBinary(int numToShow)
{
    for (int i = 0; i < 10; i++)
    {
        if (bitRead(numToShow, i) == 1)
        {
            digitalWrite(ledPin[i], HIGH);
        }
        else
        {
            digitalWrite(ledPin[i], LOW);
        }
    }
}

