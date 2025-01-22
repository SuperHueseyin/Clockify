#include <Adafruit_NeoPixel.h>

#define LED_PIN 25        // Pin, an dem der RGB-Ring angeschlossen ist
#define LED_COUNT 12     // Anzahl der LEDs im RGB-Ring

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();        // Initialisiert den RGB-Ring
  strip.show();         // Alle LEDs ausschalten
  strip.setBrightness(150); // Helligkeit (0 bis 255)
}

void loop() {
//  int ledNum = strip.numPixels();
  strip.setPixelColor(1, 155, 0, 80, 100); //setPixelColor setzt mit Dezimalwerten, weitere Optionen möglich.


  strip.fill(0x0000ffff, 6, 10); //fill funktionier nur mit 32-Bit Farbcodierung
  strip.show();
}

