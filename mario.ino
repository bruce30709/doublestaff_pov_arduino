#include "FastLED.h"
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 20
#define DATA_PIN 0
#define BRIGHTNESS 30
CRGB leds[NUM_LEDS];

CRGBPalette16 currentPalette;
TBlendType currentBlending;
uint8_t timer1=120,timer2=20,flag=0;
#define PROG_SIZE 220
uint8_t pattern[] = {
 99, 99, 99,  0,  0,  0, 99, 99, 99, 99,
 99, 99,  0,  0,  0,  0,  0,  0,  0, 99,
 99, 25, 25, 25, 40, 40, 25, 40, 99, 99,
 25, 40, 25, 25, 99, 40, 40, 40, 40, 99,
 25, 25, 25, 40, 40, 25, 25, 25, 40, 99,                 
 99, 99, 40, 40, 40, 40, 40, 40, 99, 99,
 99,  0,  0,150,  0,  0,  0, 99, 99, 99,
  0,  0,  0,150,  0,  0,150,  0,  0, 99,
 40, 40,150,150, 40,150, 40,150, 40, 40,
 40, 40,150,150,150,150,150,150, 40, 99,
 99, 99, 25, 25, 99, 99, 25, 25, 99, 99,
 99, 25, 25, 25, 99, 99, 25, 25, 25, 99,
 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
 75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,                 
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 99,
 99, 99, 75, 75, 75, 75, 75, 75, 99, 98, 
};


void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.clear();
  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;
}

void loop() {
  static uint8_t startIndex = 0;

  for (uint8_t i = 0; i < 10; ++i) {
    CRGB c; 
    if(timer1!=0 )
    {
      if (pattern[startIndex] == 99) {
        c = CRGB::Black;   
      }
      else if (pattern[startIndex] == 98 && flag==0) {
        c = CRGB::Black;  
        startIndex -= 20;
        flag=1; 
      }
      else if (pattern[startIndex] == 98) {
        c = CRGB::Black;  
      }
      else {
        c = ColorFromPalette(currentPalette, pattern[startIndex] , BRIGHTNESS, currentBlending);
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
        timer1=120; 
        timer2=20;
      }
    }
    leds[i] = c;  
    leds[19  - i] = c;
    
    if (startIndex == PROG_SIZE && flag==1)
    {
      flag=0;
      startIndex = 0;
    }
   
  }
  
  FastLED.show();
  FastLED.delay(3);
}
