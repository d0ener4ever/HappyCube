/**
 * Time Module
 * 
 * This module handles retrieving and formatting the current time using an external time source.
 * It initializes a connection to a time server over Wi-Fi and provides a function to return
 * the current time as a formatted string.
 * 
 * Author: Lukas Bochnick
 */

#ifndef TIME_MODULE_H
#define TIME_MODULE_H

#include <Arduino.h>

/**
 * Initializes the time module by connecting to a Wi-Fi network.
 * This is required to synchronize time with an NTP server.
 * 
 * @param ssid The Wi-Fi network SSID
 * @param password The Wi-Fi network password
 */
void initTimeModule(const char* ssid, const char* password);

/**
 * Returns the current time as a formatted string.
 * The format is "HH:MM:SS".
 * 
 * @return A string representing the current time in HH:MM:SS format.
 */
String getFormattedTime();

#endif // TIME_MODULE_H
