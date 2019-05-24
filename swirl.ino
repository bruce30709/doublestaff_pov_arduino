#include "FastLED.h"
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 20
#define DATA_PIN 0
#define BRIGHTNESS 50
CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType currentBlending;

#define PROG_SIZE 80
uint8_t pattern[] = {
  99, 99, 99, 13, 99, 99, 99, 99, 99, 99,
  99, 99, 13, 13, 13, 99, 99, 99, 99, 99,
  99, 13, 13, 13, 13, 13, 99, 99, 99, 99,
  99, 13, 13, 99, 13, 13, 13, 99, 99, 99,
  13, 99, 99, 99, 99, 13, 13, 13, 99, 99,
  99, 99, 99, 99, 99, 99, 13, 13, 13, 99,
  99, 99, 99, 99, 99, 99, 99, 13, 13, 99,
  99, 99, 99, 99, 99, 99, 99, 99, 13, 13,  
  
};


void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.clear();
  currentPalette = PartyColors_p;
  currentBlending = LINEARBLEND;
}

void loop() {
  static uint8_t startIndex = 0;
  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c;
    if (pattern[startIndex] == 99) {
      c = CRGB::Black;   
    }
    else {
      c = ColorFromPalette(currentPalette, pattern[startIndex]*250 , BRIGHTNESS, currentBlending);
    }
    leds[i] = c;  
    leds[19  - i] = c;
    startIndex += 1;
    if (startIndex == PROG_SIZE) startIndex = 0;
  }
  FastLED.show();
  FastLED.delay(5);
}
