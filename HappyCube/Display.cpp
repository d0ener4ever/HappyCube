/**
 * Display Implementation
 * 
 * This file implements functions for controlling an SSD1306 OLED display.
 * It supports basic text rendering, clearing, cursor positioning, bitmap drawing,
 * and frame switching. Additionally, it includes a function for centering multi-line text.
 * 
 * Author: Lukas Bochnick
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Display.h"

// Define display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // No reset pin used

// Global display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay() {
    Wire.begin(3, 1);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        for (;;); // Halt execution if display initialization fails
    }
    display.clearDisplay();
    display.display();
}

void displayClear() {
    display.clearDisplay();
}

void displaySetCursor(uint8_t col, uint8_t row) {
    display.setCursor(col, row);
}

void displayPrint(const char* text) {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.println(text);
}

void displayBitmap(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t *bitmap) {
    int width = x1 - x0 + 1;
    int height = y1 - y0 + 1;
    display.drawBitmap(x0, y0, bitmap, width, height, SSD1306_WHITE);
}

void displaySwitchFrame() {
    display.display();
}

void displayCenteredText(String text, uint8_t textSize) {
    display.setTextSize(textSize);
    display.setTextColor(WHITE);

    uint8_t charWidth = 6 * textSize;  // 5 pixels + 1 pixel spacing
    uint8_t lineHeight = 8 * textSize;
    const int maxWidth = SCREEN_WIDTH;

    // Split text into lines based on word wrapping
    String lines[10]; // Maximum 10 lines
    int lineCount = 0;
    String currentLine = "";
    int pos = 0;

    while (pos < text.length()) {
        int spaceIndex = text.indexOf(' ', pos);
        String word;
        if (spaceIndex == -1) {
            word = text.substring(pos);
            pos = text.length();
        } else {
            word = text.substring(pos, spaceIndex);
            pos = spaceIndex + 1;
        }

        int currentLineWidth = currentLine.length() * charWidth;
        int wordWidth = word.length() * charWidth;
        if (currentLine.length() > 0) {
            wordWidth += charWidth; // Account for space
        }

        if (currentLineWidth + wordWidth > maxWidth && currentLine.length() > 0) {
            lines[lineCount++] = currentLine;
            currentLine = word;
        } else {
            if (currentLine.length() > 0) {
                currentLine += " ";
            }
            currentLine += word;
        }
    }

    if (currentLine.length() > 0) {
        lines[lineCount++] = currentLine;
    }

    // Calculate vertical centering
    int totalTextHeight = lineCount * lineHeight;
    int startY = (SCREEN_HEIGHT - totalTextHeight) / 2;

    display.clearDisplay();
    for (int i = 0; i < lineCount; i++) {
        int textWidth = lines[i].length() * charWidth;
        int x = (SCREEN_WIDTH - textWidth) / 2;
        int y = startY + i * lineHeight;
        display.setCursor(x, y);
        display.println(lines[i]);
    }
    display.display();
}
