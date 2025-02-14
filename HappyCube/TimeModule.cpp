/**
 * Time Module Implementation
 * 
 * This file implements the functions for retrieving and formatting the current time 
 * using an NTP server. The module connects to Wi-Fi and fetches the current time.
 * 
 * Author: Lukas Bochnick
 */

#include "TimeModule.h"
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// Initialize NTP client with a UDP connection
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0, 60000);

void initTimeModule(const char* ssid, const char* password) {
    Serial.println();
    Serial.print("Connecting to WiFi: ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected.");

    timeClient.begin();
    timeClient.update();
}

String getFormattedTime() {
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();
    int hours = (epochTime % 86400L) / 3600;
    int minutes = (epochTime % 3600) / 60;
    int seconds = epochTime % 60;

    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", hours, minutes, seconds);
    return String(buffer);
}
