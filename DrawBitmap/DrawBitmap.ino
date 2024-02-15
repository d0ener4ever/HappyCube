#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Inkludieren Sie die Header-Datei Ihrer Bitmap
#include "my_bitmap.h" // Ersetzen Sie dies mit dem tatsächlichen Dateinamen Ihrer Bitmap

#define SCREEN_WIDTH 128 // OLED-Display Breite in Pixeln
#define SCREEN_HEIGHT 64 // OLED-Display Höhe in Pixeln

// Deklaration für ein SSD1306-Display, das über I2C verbunden ist (SDA, SCL Pins)
#define OLED_RESET    -1 // Reset-Pin ist nicht verwendet, daher -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned int blink_time = 0;

void setup() {
  // Initialisieren des OLED-Displays
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Ändern Sie 0x3C nach Bedarf, wenn Ihre I2C-Adresse anders ist
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Endlosschleife bei Fehlschlag
  }
  
  display.clearDisplay(); // Bildschirm löschen
  
  // Bitmap anzeigen
  display.drawBitmap(
    (SCREEN_WIDTH - FACE_WIDTH) / 2, (SCREEN_HEIGHT - FACE_HEIGHT) / 2, // Positionierung der Bitmap
    face, FACE_WIDTH, FACE_HEIGHT, 1); // Bitmap-Daten und Größe

  display.display(); // Änderungen auf dem Display anzeigen
  blink_time = millis();
}

void loop() {
  display.clearDisplay(); // Bildschirm löschen
  display.drawBitmap(
    ((SCREEN_WIDTH - FACE_WIDTH) / 2) + random(-5,5), ((SCREEN_HEIGHT - FACE_HEIGHT) / 2) + random(-2,2), // Positionierung der Bitmap
    face, FACE_WIDTH, FACE_HEIGHT, 1); // Bitmap-Daten und Größe
  
  display.display(); // Änderungen auf dem Display anzeigen
  delay(200);
  if(blink_time < millis()) {
    display.clearDisplay(); // Bildschirm löschen
    display.drawBitmap(
    ((SCREEN_WIDTH - FACE_WIDTH) / 2) + random(-5,5), ((SCREEN_HEIGHT - FACE_HEIGHT) / 2) + random(-2,2), // Positionierung der Bitmap
    blink, FACE_WIDTH, FACE_HEIGHT, 1); // Bitmap-Daten und Größe
  
    display.display(); // Änderungen auf dem Display anzeigen
    delay(random(200, 300));//random(200, 300)
    blink_time = millis() + random(4000,6000);
  }
}
