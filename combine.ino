#include "FastLED.h"
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 20
#define DATA_PIN 0
#define PROG_SIZE 100
#define BRIGHTNESS 30
#define reset_time 20
#define delay_time 5
const int reset_round=reset_time*100;
CRGB leds[NUM_LEDS];
const uint8_t pattern[] PROGMEM= {
  13, 99, 99, 99, 99, 99, 99, 99, 99, 99,
  13, 13, 99, 99, 99, 99, 99, 99, 99, 99,
  13, 13, 13, 99, 99, 99, 99, 99, 99, 99,
  99, 13, 13, 13, 99, 99, 99, 99, 99, 99,
  99, 99, 13, 13, 13, 99, 99, 99, 99, 99,
  99, 99, 99, 13, 13, 13, 99, 99, 99, 99,
  99, 99, 99, 99, 13, 13, 13, 99, 99, 99,
  99, 99, 99, 99, 99, 13, 13, 13, 13, 99,
  99, 99, 99, 99, 99, 99, 13, 13, 13, 13,
  99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
const uint8_t pattern2[] PROGMEM= {
  15, 99, 99, 99, 99, 99, 99, 99, 99, 15,
  15, 15, 99, 99, 99, 99, 99, 99, 15, 15,
  15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
  99, 99, 99, 15, 15, 15, 15, 99, 99, 99,
  99, 99, 99, 99, 15, 15, 99, 99, 99, 99,
  99, 99, 99, 99, 15, 15, 15, 99, 99, 99,
  15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
  15, 15, 99, 99, 99, 99, 99, 99, 15, 15,
  15, 99, 99, 99, 99, 99, 99, 99, 99, 15,
  99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
const uint8_t pattern3[] PROGMEM= {
  99, 99, 99,  99,  1, 99, 99, 99, 99, 99,
  99, 99, 99,   1,  2,  1, 99, 99, 99, 99,
  99, 99,  1,   2,  2,  2,  1, 99, 99, 99,
  99,  1,  2,   3,  3,  3,  2,  1, 99, 99,
   1,  2,  3,   4,  4,  4,  3,  2,  1, 99,
  99,  1,  2,   3,  3,  3,  2,  1, 99, 99,
  99, 99,  1,   2,  2,  2,  1, 99, 99, 99,
  99, 99, 99,   1,  2,  1, 99, 99, 99, 99,
  99, 99, 99,  99,  1, 99, 99, 99, 99, 99, 
  99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
};
void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.setBrightness( BRIGHTNESS );
}

void loop() {
  static uint8_t startIndex = 0;
  for(int i = 0; i < reset_round; ++i) {
  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c; 
      if ((char)pgm_read_byte(&(pattern[startIndex])) == 99) {
        c = CRGB::Black;   
      }
      else if ((char)pgm_read_byte(&(pattern[startIndex])) == 15) {
        c = CRGB::Pink;  
      }
      else if ((char)pgm_read_byte(&(pattern[startIndex])) == 13) {
        c = CRGB::Purple;  
      }
      startIndex += 1;    
    
    leds[i] = c;  
    leds[19  - i] = c;   
  }
  FastLED.show();
  FastLED.delay(delay_time);
  if(startIndex==PROG_SIZE)
    startIndex=0;
  }
  startIndex = 0;

  for(int i = 0; i < reset_round; ++i) {
  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c; 
      if ((char)pgm_read_byte(&(pattern2[startIndex])) == 99) {
        c = CRGB::Black;   
      }
      else if ((char)pgm_read_byte(&(pattern2[startIndex])) == 13) {
        c = CRGB::LightPink;  
      }
      else if ((char)pgm_read_byte(&(pattern2[startIndex])) == 15) {
        c = CRGB::MediumPurple;  
      }
      startIndex += 1;    
    
    leds[i] = c;  
    leds[19  - i] = c;   
  }
  FastLED.show();
  FastLED.delay(delay_time);
  if(startIndex==PROG_SIZE)
    startIndex=0;
  }
  startIndex = 0;
  for(int i = 0; i < reset_round; ++i) {
  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c; 
      if ((char)pgm_read_byte(&(pattern3[startIndex])) == 99) {
        c = CRGB::Black;   
      }
      else if ((char)pgm_read_byte(&(pattern3[startIndex])) == 1) {
        c = CRGB::MediumVioletRed;
      }
      else if ((char)pgm_read_byte(&(pattern3[startIndex])) == 2) {
        c = CRGB::Red;  
      }
      else if ((char)pgm_read_byte(&(pattern3[startIndex])) == 3) {
        c = CRGB::Orange;  
      }
      else if ((char)pgm_read_byte(&(pattern3[startIndex])) == 4) {
        c = CRGB::Yellow;  
      }
      startIndex += 1;    
    
    leds[i] = c;  
    leds[19  - i] = c;   
  }
  FastLED.show();
  FastLED.delay(delay_time);
  if(startIndex==PROG_SIZE)
    startIndex=0;
  }
}
