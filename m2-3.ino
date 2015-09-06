void setup()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        pinMode(currentPin, OUTPUT);
    }

}

void loop()
{
    int ledDelay = 1000;
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        digitalWrite(currentPin - 1, LOW);
        digitalWrite(currentPin, HIGH);
        if (currentPin != 13)
        {
            delay(ledDelay);
        }
        ledDelay /= 2;
    }

    ledDelay = 1000;
    for (int currentPin = 13; currentPin >= 2; currentPin--)
    {
        digitalWrite(currentPin, HIGH);
        digitalWrite(currentPin + 1, LOW);
        if (currentPin != 2)
        {
            delay(ledDelay);
        }
        ledDelay /= 2;
    }
}
