#define RUNNINGTIME 15000

const int ledPin = 13;

int ledState = LOW;
long ledPreviousMillis = 0;
long previousMillis = 0;

long interval = 1000;

const float decreaseSpeed = (float) interval / RUNNINGTIME;

void setup() {
  Serial.begin(9600);
  Serial.println(decreaseSpeed);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  Serial.println(interval);
  
  unsigned long currentMillis = millis();
  
  if(currentMillis - ledPreviousMillis > interval) {
    ledPreviousMillis = currentMillis;

    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
      if (interval > 1)
      {
          interval = interval - decreaseSpeed * (currentMillis - previousMillis);
          previousMillis = currentMillis;
      }
    }

    digitalWrite(ledPin, ledState);
  }
}
