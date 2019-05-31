#include "FastLED.h"
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 20
#define DATA_PIN 0
#define BRIGHTNESS 30
CRGB leds[NUM_LEDS];
uint8_t timer1=140,timer2=20;
#define PROG_SIZE 140
uint8_t pattern[] = {
 99, 99, 99,  0,  0,  0, 70, 99, 99, 99,
 99, 99, 70,  0,  0,  0, 70, 70, 99, 99,
 99, 70, 70,  0,  0,  0, 70, 70, 70, 99,
 99, 70, 70,  0,  0,  0,  0, 70, 70, 99,
 99,  0,  0,  0, 70,  0,  0,  0,  0, 99,
  0,  0,  0, 70, 70, 70,  0,  0, 70,  0,  
 70, 70,  0, 70, 70, 70,  0, 70, 70, 70,
 70, 70,  0,  0, 70,  0,  0,  0, 70,  0,                
 70,  0, 99, 99, 99, 99, 99, 99,  0,  0,
 99, 99, 50, 99, 50, 50, 99, 50, 99, 99,
 99, 50, 50, 99, 50, 50, 99, 50, 50, 99,
 99, 50, 50, 50, 50, 50, 50, 50, 50, 99,
 99, 50, 50, 50, 50, 50, 50, 50, 50, 99,
 99, 99, 50, 50, 50, 50, 50, 50, 99, 99,
};


void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.setBrightness( BRIGHTNESS );
}

void loop() {
  static uint8_t startIndex = 0;

  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c; 
    if(timer1!=0 )
    {
      if (pattern[startIndex] == 70) {
        c = CRGB::White;  
      }
      else if (pattern[startIndex] == 0){
        c = CRGB::Red;
      }
      else if (pattern[startIndex] == 99){
        c = CRGB::Black;
      }
      else if (pattern[startIndex] ==50){
        c = CRGB::Khaki;
      }
      timer1--;  
      startIndex += 1;    
    }
    else
    {
      c = CRGB::Black;
      timer2--;
      if(timer2==0)
      { 
        timer1=140; 
        timer2=20;
      }
    }
    leds[i] = c;  
    leds[19  - i] = c;
    if (startIndex == PROG_SIZE) startIndex = 0;
   
  }
  
  FastLED.show();
  FastLED.delay(3);
}
