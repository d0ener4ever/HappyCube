/**
 * HappyCube Main Program
 * 
 * This program controls the HappyCube, an interactive display that can show the time
 * or function as a Magic 8-Ball. A button press triggers different behaviors:
 * - Short press: Displays a random Magic 8-Ball answer.
 * - Long press (2 seconds): Displays the current time.
 * 
 * Author: Lukas Bochnick
 */

#include "Display.h"
#include "FaceAnimation.h"
#include "Magic8Ball.h"
#include "TimeModule.h"
#include <Arduino.h>

#define BUTTON_PIN 2

// Button press tracking variables
unsigned long buttonPressStart = 0;
bool buttonLongPressed = false;
const unsigned long longPressDuration = 2000; // Duration for a long press in milliseconds

// Initialize face animation with position and size parameters
FaceAnimation face(0, 0, 1, 1, 32);

void setup() {
    Serial.begin(115200);
    initDisplay();
    
    // Initialize the time module (Wi-Fi credentials should be set separately)
    initTimeModule("Your SSID", "Your Password");
    
    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
    bool buttonState = (digitalRead(BUTTON_PIN) == LOW);

    if (buttonState) {
        if (buttonPressStart == 0) {
            // Start timing the button press
            buttonPressStart = millis();
        } else if (millis() - buttonPressStart > longPressDuration && !buttonLongPressed) {
            // Long press detected, display the current time
            buttonLongPressed = true;
            String currentTime = getFormattedTime();
            displayCenteredText(currentTime);
            delay(3000);
        }
    } else {
        if (buttonPressStart != 0 && !buttonLongPressed) {
            // Short press detected, display a random Magic 8-Ball answer
            String wisdom = getRandom8BallAnswer();
            displayCenteredText(wisdom);
            delay(3000);
        }
        // Reset button press tracking variables
        buttonPressStart = 0;
        buttonLongPressed = false;
    }

    // Continue face animation
    updateFacePosition(face);
    displayClear();
    drawFace(face);
    displaySwitchFrame();
    delay(100);
}