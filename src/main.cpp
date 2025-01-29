#include <Adafruit_NeoPixel.h>
#include <time.h>

#define LED_PIN 25        // Pin, an dem der RGB-Ring angeschlossen ist
#define LED_COUNT 12     // Anzahl der LEDs im RGB-Ring
#define BTN 35


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();        // Initialisiert den RGB-Ring
  strip.show();         // Alle LEDs ausschalten
  strip.setBrightness(50); // Helligkeit (0 bis 255)
  pinMode(BTN, INPUT_PULLUP);
  srand(time(0));
}

void loop() {
//  int ledNum = strip.numPixels();
//strip.setPixelColor(0, 155, 0, 80, 100); //setPixelColor setzt mit Dezimalwerten, weitere Optionen möglich.
/*
strip.fill(0xffff0000, 6, 11); //fill funktionier nur mit 32-Bit Farbcodierung
strip.fill(0x0000ffff, 0, 6); //fill funktionier nur mit 32-Bit Farbcodierung
strip.show();

delay(1000);

for(int i = 0; i < strip.numPixels()/2;i++){
  strip.setPixelColor(i, 0, 0, 255);
  delay(100);
  strip.show();
}
*/
/*
delay(1000); 

for(int i = 0; i <strip.numPixels(); i++){
  strip.setPixelColor(strip.numPixels()-1-i, 0, 0, 0);
  delay(100);
  strip.show();
}
*/
/*
delay(1000);


  for(int i = 0; i < 6; i++){
    
    for(int j = 0; j < strip.numPixels(); j++){
      int rando1= rand()%256;
      int rando2= rand()%256;
      int rando3= rand()%256;
      strip.setPixelColor(j, rando1, rando2, rando3);
      delay(100);
      strip.show();
    }
  }
*/
  strip.show();
  delay(500); 
}

