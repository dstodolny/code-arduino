int currentPin = 2;
int goLeft = 1;

void setup()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        pinMode(currentPin, OUTPUT);
    }

}

void loop()
{
    digitalWrite(currentPin, HIGH);
    delay(50);
    
    if (currentPin == 13)
    {
        goLeft = 0;
    }
    else if (currentPin == 2)
    {
        goLeft = 1;
    }
   
    digitalWrite(currentPin, LOW);

    if (goLeft == 1)
    {   
        currentPin++;
    }
    else
    {
        currentPin--;
    }
}
