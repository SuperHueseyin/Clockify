#include <Adafruit_NeoPixel.h>

#define LED_PIN 25        // Pin, an dem der RGB-Ring angeschlossen ist
#define LED_COUNT 12     // Anzahl der LEDs im RGB-Ring

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();        // Initialisiert den RGB-Ring
  strip.show();         // Alle LEDs ausschalten
  strip.setBrightness(50); // Helligkeit (0 bis 255)
}

// Funktion: Erzeugt eine Farbe basierend auf der Position im Farbrad
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Funktion: Regenbogeneffekt
void rainbowCycle(int wait) {
  for (int j = 0; j < 256 * 5; j++) { // 5 volle Zyklen durchlaufen
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void loop() {
  rainbowCycle(1);     // Starte eine Regenbogenanimation
}

