#include <string.h>
#include <stdbool.h>

#define PASSWORD_LIMIT 4

const int correctPassword[PASSWORD_LIMIT] = {2, 3, 1, 1}; // Correct password: 2311

const int pinRed = 12;
const int pinGreen = 10;
const int pushButton = 7;

// Timing variabels
long newDigitMillis = 0;
long resetMillis = 0;
long resetInterval = 1000;
long digitInterval = 300;

int currentPassword[PASSWORD_LIMIT] = {0, 0, 0, 0};
int currentSlot = 0;
int currentDigit = 0;

bool buttonPressed = false;
int buttonState = 0;
int lastButtonState = 0;

bool unlocked = false;

void setup() {
    Serial.begin(9600);
    
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    pinMode(pushButton, INPUT);
}

void loop() {
    unsigned long currentMillis = millis();
    int buttonState = digitalRead(pushButton);
    
    if (currentSlot > PASSWORD_LIMIT - 1) {
        currentSlot = 0;
    }

    if (buttonState != lastButtonState && buttonState == HIGH) {
        if (currentDigit > 9) {
            currentDigit = 0;
        }
        newDigitMillis = currentMillis;
        resetMillis = currentMillis;
        currentDigit++;
        buttonPressed = true;
    }

    lastButtonState = buttonState;
    
    if (currentMillis - newDigitMillis > digitInterval) {
        newDigitMillis = currentMillis;
        if (buttonPressed) {
            if (currentDigit != 0) {
                currentPassword[currentSlot++] = currentDigit;
            }
            currentDigit = 0;
        }
         
        if (currentMillis - resetMillis > resetInterval) {
            printPassword();
            resetMillis = currentMillis;

            if (memcmp(correctPassword, currentPassword, sizeof(correctPassword)) == 0) {
                Serial.println("*Click* The secret safe is unlocked! Now quick, grab the treasure and get out of here!");
                unlocked = 1;
            }
            else {
                if (buttonPressed) {
                    lock();
                }     
                resetPassword();
            }
        }
    }

    if (unlocked) {
        unlock();
    }
    
    delay(1);
}

void lock() {
    Serial.println("Forgot password? Enter your email... Hah! Just joking. I'm a goddamn secret safe - not a web app. Go away!");
    digitalWrite(pinRed, HIGH);
    delay(1000);
    digitalWrite(pinRed, LOW);
}

void unlock() {
    digitalWrite(pinGreen, HIGH);
}

void printPassword() {
      Serial.print("Your password: ");    
      for (int i = 0; i < PASSWORD_LIMIT; i++) {
          Serial.print(currentPassword[i]);
      }
      Serial.println();
}

void resetPassword() {
    for (int i = 0; i < PASSWORD_LIMIT; i++) {
        currentPassword[i] = 0;
    }
    currentSlot = 0;
    buttonPressed = false;
}

