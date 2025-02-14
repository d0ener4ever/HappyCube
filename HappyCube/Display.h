/**
 * Display Module
 * 
 * This module provides functions to control a graphical display.
 * It supports basic text output, cursor positioning, clearing the screen,
 * rendering bitmaps, and frame switching.
 * 
 * Author: Lukas Bochnick
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

/**
 * Initializes the display hardware.
 */
void initDisplay();

/**
 * Clears the entire display.
 */
void displayClear();

/**
 * Sets the cursor position for text output.
 * 
 * @param col Column position (0-based)
 * @param row Row position (0-based)
 */
void displaySetCursor(uint8_t col, uint8_t row);

/**
 * Prints a string to the display at the current cursor position.
 * 
 * @param text The text to be printed
 */
void displayPrint(const char* text);

/**
 * Renders a bitmap on the display at a specified location.
 * 
 * @param x0 Starting x-coordinate
 * @param y0 Starting y-coordinate
 * @param x1 Ending x-coordinate
 * @param y1 Ending y-coordinate
 * @param bitmap Pointer to the bitmap data
 */
void displayBitmap(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, const uint8_t *bitmap);

/**
 * Switches between display frames (if using double-buffering).
 */
void displaySwitchFrame();

/**
 * Displays multi-line text centered on the screen.
 * 
 * @param text The text to display
 * @param textSize Font size (default is 2)
 */
void displayCenteredText(String text, uint8_t textSize = 2);

#endif // DISPLAY_H
