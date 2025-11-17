#include <Wire.h>
#include <LiquidCrystal.h>
#include "PAJ7620.h"

// Pin connections
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // RS, E, D4, D5, D6, D7 for LCD
const int gestureSensorSDA = A4; // I2C SDA
const int gestureSensorSCL = A5; // I2C SCL

// Predefined password sequence
const int presetPassword[] = {1, 4, 7, 3}; // Example password: Up, Right, Clockwise, Left
const int passwordLength = 4;

int enteredPassword[passwordLength];
int index = 0;
bool passwordEntryMode = false;
bool locked = true;

void setup() {
    Wire.begin();
    lcd.begin(16, 2);
    lcd.print("Locked");
    delay(1000);
    lcd.clear();
    
    if (PAJ7620_init()) {
        lcd.print("Gesture Sensor OK");
        delay(1000);
    } else {
        lcd.print("Gesture Sensor FAIL");
        while (1);
    }
    lcd.clear();
    lcd.print("Locked");
}

void loop() {
    uint8_t gesture = 0;
    if (PAJ7620ReadReg(0x43, 1, &gesture)) {
        if (gesture) {
            handleGesture(gesture);
        }
    }
}

void handleGesture(uint8_t gesture) {
    if (gesture == GES_WAVE_FLAG) {
        if (!passwordEntryMode) {
            passwordEntryMode = true;
            index = 0;
            lcd.clear();
            lcd.print("Enter Password");
        } else {
            passwordEntryMode = false;
            locked = true;
            lcd.clear();
            lcd.print("Locked");
        }
    }
    
    if (passwordEntryMode) {
        int value = mapGestureToNumber(gesture);
        if (value != 0) {
            lcd.clear();
            lcd.print(getGestureName(value));
            delay(1000);
            
            if (value == presetPassword[index]) {
                enteredPassword[index] = value;
                index++;
                
                if (index == passwordLength) {
                    verifyPassword();
                }
            } else {
                lcd.clear();
                lcd.print("Locked");
                passwordEntryMode = false;
                index = 0;
            }
        }
    }
}

int mapGestureToNumber(uint8_t gesture) {
    switch (gesture) {
        case GES_UP_FLAG: return 1;
        case GES_DOWN_FLAG: return 2;
        case GES_LEFT_FLAG: return 3;
        case GES_RIGHT_FLAG: return 4;
        case GES_FORWARD_FLAG: return 5;
        case GES_BACKWARD_FLAG: return 6;
        case GES_CLOCKWISE_FLAG: return 7;
        case GES_ANTI_CLOCKWISE_FLAG: return 8;
        default: return 0;
    }
}

const char* getGestureName(int value) {
    switch (value) {
        case 1: return "Up";
        case 2: return "Down";
        case 3: return "Left";
        case 4: return "Right";
        case 5: return "Forward";
        case 6: return "Backward";
        case 7: return "Clockwise";
        case 8: return "Anticlockwise";
        default: return "Unknown";
    }
}

void verifyPassword() {
    bool match = true;
    for (int i = 0; i < passwordLength; i++) {
        if (enteredPassword[i] != presetPassword[i]) {
            match = false;
            break;
        }
    }

    if (match) {
        lcd.clear();
        lcd.print("Unlocked");
        locked = false;
    } else {
        lcd.clear();
        lcd.print("Locked");
    }
    passwordEntryMode = false;
    index = 0;
}

