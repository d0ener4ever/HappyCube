/**
 * Magic 8-Ball Module
 * 
 * This module defines a set of predefined answers for a Magic 8-Ball simulation.
 * The responses are stored in PROGMEM to optimize memory usage on microcontrollers.
 * The function `getRandom8BallAnswer()` provides a random response when called.
 * 
 * Author: Lukas Bochnick
 */

#ifndef MAGIC_8_BALL_H
#define MAGIC_8_BALL_H

#include <Arduino.h>

/**
 * Predefined Magic 8-Ball responses stored in PROGMEM.
 * These responses mimic the original Magic 8-Ball toy.
 */
const char PROGMEM answer0[]  = "It is certain";
const char PROGMEM answer1[]  = "It is decidedly so";
const char PROGMEM answer2[]  = "Without a doubt";
const char PROGMEM answer3[]  = "Yes - definitely";
const char PROGMEM answer4[]  = "You may rely on it";
const char PROGMEM answer5[]  = "As I see it, yes";
const char PROGMEM answer6[]  = "Most likely";
const char PROGMEM answer7[]  = "Outlook good";
const char PROGMEM answer8[]  = "Yes";
const char PROGMEM answer9[]  = "Signs point to yes";
const char PROGMEM answer10[] = "Reply hazy, try again";
const char PROGMEM answer11[] = "Ask again later";
const char PROGMEM answer12[] = "Better not tell you now";
const char PROGMEM answer13[] = "Cannot predict now";
const char PROGMEM answer14[] = "Concentrate and ask again";
const char PROGMEM answer15[] = "Don't count on it";
const char PROGMEM answer16[] = "My reply is no";
const char PROGMEM answer17[] = "My sources say no";
const char PROGMEM answer18[] = "Outlook not so good";
const char PROGMEM answer19[] = "Very doubtful";

/**
 * Array storing pointers to all predefined answers.
 * Stored in PROGMEM to conserve SRAM.
 */
static const char * const answers[] PROGMEM = {
  answer0,  answer1,  answer2,  answer3,  answer4,
  answer5,  answer6,  answer7,  answer8,  answer9,
  answer10, answer11, answer12, answer13, answer14,
  answer15, answer16, answer17, answer18, answer19
};

/**
 * Number of available responses.
 */
const uint8_t NUM_ANSWERS = sizeof(answers) / sizeof(answers[0]);

/**
 * Retrieve a random Magic 8-Ball response.
 * 
 * @return A randomly selected answer as a String.
 */
String getRandom8BallAnswer();

#endif // MAGIC_8_BALL_H
