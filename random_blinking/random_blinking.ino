#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "FastLED.h"
\\set the number of LEDs on your project
#define NUM_LEDS 238  
#define COLOR_ORDER GRB

\\instantiate the global variables
int randomNumber;
int randomDelay;

CRGB leds[NUM_LEDS];
void setup() { 
  \\start out by setting all LEDs on white
  FastLED.addLeds<NEOPIXEL, 5>(leds, NUM_LEDS); 
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::White;
  }
  FastLED.show();
}

void loop() {
  \\set each LED individually on a random colour 
  for(int i = 0; i < NUM_LEDS; i++){
    randomNumberGenerator();
    int r = randomNumber;
    randomNumberGenerator();
    int g = randomNumber;
    randomNumberGenerator();
    int b = randomNumber;
    leds[i] = CRGB(r,g,b);
  }
  FastLED.show();
  \\at each iteration, make the delay randomly vary between 0.5 and 2 seconds
  randomDelayGenerator();
  delay(randomDelay);
}

void randomNumberGenerator(){
 randomNumber = random8(0,255); 
}

void randomDelayGenerator(){
  randomDelay = random8(500,2000);
}
