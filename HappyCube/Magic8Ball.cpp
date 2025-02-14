/**
 * Magic 8-Ball Implementation
 * 
 * This file implements the logic for retrieving a random Magic 8-Ball response.
 * The predefined responses are stored in PROGMEM to optimize memory usage.
 * 
 * Author: Lukas Bochnick
 */

#include "Magic8Ball.h"
#include <avr/pgmspace.h>

String getRandom8BallAnswer() {
  uint8_t index = random(NUM_ANSWERS); // Generate a random index
  char buffer[30]; // Buffer to store the retrieved answer

  // Copy the answer from PROGMEM to RAM
  strcpy_P(buffer, (char*)pgm_read_ptr(&(answers[index])));

  return String(buffer); // Convert to String and return
}
