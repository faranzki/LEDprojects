//#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include <FastLED.h>
#define NUM_LEDS 75
#define DATA_PIN 5
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int time_in_min = 2; // Insert timer time in minutes here

int time_in_msec = time_in_min * 60 * 1000;
int time_for_green = time_in_msec / 5 * 4; // 4/5 of time green
int time_for_yellow = time_in_msec / 5 / 3 * 2; // 2/3 of 1/5
int time_for_red = time_in_msec / 5 / 3 * 1; //1/3 of 1/5
int delay_green = time_for_green / NUM_LEDS * 2;  //correction for halving of the LED counter
int delay_yellow = time_for_yellow / NUM_LEDS * 2; // correction for halving of the LED counter
int delay_red = time_for_red / NUM_LEDS * 2; // correction for halving of the LED counter
int time_per_colour = time_in_msec / 3;
int delay_per_LED = time_per_colour / NUM_LEDS * 2; //correction for the halving of the led counter

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  delay(10);

  for(int x = 0; x < NUM_LEDS; x++){
    leds[x] = CRGB(0,255,0);
    FastLED.show();
    delay(0.5);
  }

  for(int y = 0; y < NUM_LEDS / 2 + 1; y++){
    delay(delay_green);
    leds[y] = CRGB::Black;
    leds[NUM_LEDS - y] = CRGB::Black;
    FastLED.show();
    }

  for(int z = 0; z < NUM_LEDS; z++){
    leds[z] = CRGB(255,255,0);
    FastLED.show();
    delay(0.5);
  }

  for(int y = 0; y < NUM_LEDS / 2 + 1; y++){
    delay(delay_yellow);
    leds[y] = CRGB::Black;
    leds[NUM_LEDS - y] = CRGB::Black;
    FastLED.show();
  }

  for(int v = 0; v < NUM_LEDS; v++){
    leds[v] = CRGB(255,0,0);
    FastLED.show();
    delay(0.5);
  }


  for(int y = 0; y < NUM_LEDS / 2 + 1; y++){
    delay(delay_red);
    leds[y] = CRGB::Black;
    leds[NUM_LEDS - y] = CRGB::Black;
    FastLED.show();
  }
}

void loop() {

    leds[0] = CRGB(255,0,255);
    leds[1] = CRGB(255,0,255);
    leds[2] = CRGB(255,0,255);
    FastLED.show();
    delay(30);

  for(int a = 3; a < NUM_LEDS; a++){
    leds[a - 3] = CRGB::Black;
    leds[a] = CRGB(255,0,255);
    FastLED.show();
    delay(50);
  }

  leds[NUM_LEDS] = CRGB(255,0,255);
  leds[NUM_LEDS - 1] = CRGB(255,0,255);
  leds[NUM_LEDS - 2] = CRGB(255,0,255);
  FastLED.show();
  delay(30);

  for(int a = 0; a < NUM_LEDS; a++){
    leds[NUM_LEDS - a] = CRGB::Black;
    leds[NUM_LEDS - 3 - a] = CRGB(255,0,255);
    FastLED.show();
    delay(50);
  }

    leds[0] = CRGB(0,0,255);
    leds[1] = CRGB(0,0,255);
    leds[2] = CRGB(0,0,255);
    FastLED.show();
    delay(30);

  for(int a = 3; a < NUM_LEDS; a++){
    leds[a - 3] = CRGB::Black;
    leds[a] = CRGB(0,0,255);
    FastLED.show();
    delay(50);
  }

  leds[NUM_LEDS] = CRGB(0,0,255);
  leds[NUM_LEDS - 1] = CRGB(0,0,255);
  leds[NUM_LEDS - 2] = CRGB(0,0,255);
  FastLED.show();
  delay(30);

  for(int a = 0; a < NUM_LEDS; a++){
    leds[NUM_LEDS - a] = CRGB::Black;
    leds[NUM_LEDS - 3 - a] = CRGB(0,0,255);
    FastLED.show();
    delay(50);
  }

    leds[0] = CRGB(153,0,76);
    leds[1] = CRGB(153,0,76);
    leds[2] = CRGB(153,0,76);
    FastLED.show();
    delay(30);

  for(int a = 3; a < NUM_LEDS; a++){
    leds[a - 3] = CRGB::Black;
    leds[a] = CRGB(153,0,76);
    FastLED.show();
    delay(50);
  }

  leds[NUM_LEDS] = CRGB(153,0,76);
  leds[NUM_LEDS - 1] = CRGB(153,0,76);
  leds[NUM_LEDS - 2] = CRGB(153,0,76);
  FastLED.show();
  delay(30);

  for(int a = 0; a < NUM_LEDS; a++){
    leds[NUM_LEDS - a] = CRGB::Black;
    leds[NUM_LEDS - 3 - a] = CRGB(153,0,76);
    FastLED.show();
    delay(50);    
  }

  for(int a = 0; a < NUM_LEDS; a++){
    leds[a] = CRGB::Black;
    FastLED.show();
    delay(0.5);
  }

}
