#define LEFTBUTTON 14
#define RIGHTBUTTON 15
#define PERIOD 5

struct WavePart
{
    int pin;
    unsigned long previousMillis;
    int currentDelay;
    int onDelay;
    int state;
};

WavePart *wave[5] = {
  new WavePart(),
  new WavePart(),
  new WavePart(),
  new WavePart(),
  new WavePart()
};

int lastLeftButtonState = LOW;
int lastRightButtonState = LOW;

void setup()
{
    setupLeds();
    setupWaveParts();
    setupButtons();
}

void loop()
{
    unsigned long currentMillis = millis();
    int leftButtonState = digitalRead(LEFTBUTTON);
    int rightButtonState = digitalRead(RIGHTBUTTON);

    for (int i = 0; i < 5; i++)
    {
      if (currentMillis - wave[i]->previousMillis > wave[i]->currentDelay)
      {
          wave[i]->previousMillis = currentMillis;
  
          if (wave[i]->state == LOW)
          {
              wave[i]->state = HIGH;
              wave[i]->currentDelay = wave[i]->onDelay;
          }
          else
          {
              wave[i]->state = LOW;
              wave[i]->currentDelay = PERIOD - wave[i]->onDelay;
          }
  
          digitalWrite(wave[i]->pin, wave[i]->state);
      }
    }
    
    // Buttons
    if (leftButtonState != lastLeftButtonState && leftButtonState == HIGH && wave[4]->pin <= 13)
    {
        resetWave();
        for (int i = 0; i < 5; i++)
        {
            wave[i]->pin++;
        }
    }
    else if (rightButtonState != lastRightButtonState && rightButtonState == HIGH && wave[0]->pin >= 2)
    {
        resetWave();
        for (int i = 0; i < 5; i++)
        {
            wave[i]->pin--;
        }
    }

    lastLeftButtonState = leftButtonState;
    lastRightButtonState = rightButtonState;
}

void setupLeds()
{
    for (int currentPin = 2; currentPin <= 13; currentPin++)
    {
        pinMode(currentPin, OUTPUT);
    }
}

void setupWaveParts()
{
    for (int i = 0; i < 5; i++)
    {
        wave[i]->pin = 13 - i;
        wave[i]->onDelay = 5 - i;
        wave[i]->currentDelay = wave[i]->onDelay;
        wave[i]->previousMillis = 0;
        wave[i]->state = LOW;
    } 
}

void setupButtons()
{
    pinMode(LEFTBUTTON, INPUT);
    pinMode(RIGHTBUTTON, INPUT);
}

void resetWave()
{
    for (int i = 2; i <= 13; i++)
    {
        digitalWrite(i, LOW);
    }
}

