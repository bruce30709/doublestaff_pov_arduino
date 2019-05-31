#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        0 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 20 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 190 // Time (in milliseconds) to pause between pixels
short timer=10;
short t1,t2,t3;
short a[]={30,30,30,30,0,0,0,0,30,30,30,30,0,0,0,0,30,30,30,30},b[]={0,0,30,30,30,30,0,0,0,0,0,0,0,0,30,30,30,30,0,0},c[]={0,0,0,0,0,0,30,30,30,30,30,30,30,30,0,0,0,0};
void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  int t=2;
  for(int i=0; i< (NUMPIXELS/2); i++) { // For each pixel...

    for(int j=i;j<t;j++)
    { 
      // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
      // Here we're using a moderately bright green color:
      if(timer<10&&timer>0)
      {
        pixels.setPixelColor(j, pixels.Color(a[j], b[j], c[j]));  
        pixels.show();   // Send the updated pixel colors to the hardware.
      
      }
      else if(timer<0)
      {
        t1=random(30),t2=random(30),t3=random(30);
        pixels.setPixelColor(j, pixels.Color(t1, t2, t3)); 
        pixels.setPixelColor(19-j, pixels.Color(t1, t2, t3));   
        pixels.setPixelColor(j+1, pixels.Color(t1, t2, t3)); 
        pixels.setPixelColor(19-j-1, pixels.Color(t1, t2, t3)); 
        pixels.show();
        j++;
        i++;
      }
    }
    t+=2; 


    //delay(DELAYVAL); // Pause before next pass through loop
  }
  
  delay(DELAYVAL);
  if(timer>0)
  {
    for(int i=0; i< NUMPIXELS; i++)
    {
       pixels.setPixelColor(i, pixels.Color(0, 0, 0)); 
       pixels.show();
    }
    delay(DELAYVAL);
  }
  if(timer>0)
  timer--;
  else if(timer>-10)
  timer--;
  else
  timer=10;

}
