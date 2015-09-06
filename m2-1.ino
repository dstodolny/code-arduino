void setup()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        pinMode(currentPin, OUTPUT);
    }

}

void loop()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        digitalWrite(currentPin - 1, LOW);
        digitalWrite(currentPin, HIGH);
        if (currentPin != 13)
        {
            delay(50);
        }
    }

    for (int currentPin = 13; currentPin >= 2; currentPin--)
    {
        digitalWrite(currentPin, HIGH);
        digitalWrite(currentPin + 1, LOW);
        if (currentPin != 2)
        {
            delay(50);
        }
    }
}
