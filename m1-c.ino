#define MAXINTERVAL 20
#define MININTERVAL 1
#define RUNNINGTIME 5000

const int ledPin = 13;
int ledState = LOW;

float blinkSpeed = (float) (MAXINTERVAL - MININTERVAL) / RUNNINGTIME;

int offInterval = 10;
int onInterval = MININTERVAL;

int interval = onInterval;

long int previousMillis = 0;
long int previousStateMillis = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    long int currentMillis = millis();

    if (currentMillis - previousStateMillis > (float) RUNNINGTIME / (MAXINTERVAL - MININTERVAL) && onInterval < 20)
    {
        previousStateMillis = currentMillis;
        onInterval++;
    }

    if (currentMillis - previousMillis > interval)
    {
        previousMillis = currentMillis;

        if (ledState == LOW)
        {
            ledState = HIGH;
            interval = onInterval;
        }
        else
        {
            ledState = LOW;
            interval = offInterval;
        }

        digitalWrite(ledPin, ledState);
    }
    
}
