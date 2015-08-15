const int ledPin =  12;

int ledState = LOW;
long previousMillis = 0;

long interval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);      
}

void loop()
{
  Serial.println(interval);
  
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;

    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(ledPin, ledState);
  }

  interval--;
  delay(15); 
}
