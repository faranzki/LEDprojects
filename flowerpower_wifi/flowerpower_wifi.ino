#include "config.h"
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#include "FastLED.h"
#define NUM_LEDS 238
#define DATA_PIN 5
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

AdafruitIO_Feed *colour = io.feed("colour");
AdafruitIO_Feed *party = io.feed("party");
AdafruitIO_Feed *gay = io.feed("gay");
AdafruitIO_Feed *test = io.feed("test");

int r;
int g;
int b;

int start_partyTime;
int start_gayTime;

int randomNumber;
int randomDelay;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::White;
  }
  FastLED.show();

  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  colour->onMessage(setColour);
  party->onMessage(startParty);
  gay->onMessage(startGayTime);

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());

  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::White;
  }
  FastLED.show();
}

void loop() {
  io.run();
  if(start_gayTime == 1){
    gayTime();  
  }
  else if(start_partyTime == 1){
    partyTime();
  }
  else{
    displayColour();
  }
  delay(500);
}

void setColour(AdafruitIO_Data *data){
  Serial.println("Received:");
  Serial.print("  - R: ");
  Serial.println(data->toRed());
  Serial.print("  - G: ");
  Serial.println(data->toGreen());
  Serial.print("  - B: ");
  Serial.println(data->toBlue());
  Serial.print("  - HEX: ");
  Serial.println(data->value());
  r = data->toRed();
  g = data->toGreen();
  b = data->toBlue();
}

void displayColour(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(r,g,b);
  }
  FastLED.show();
}

void startParty(AdafruitIO_Data *data){
  start_partyTime = data->toPinLevel();
}

void startGayTime(AdafruitIO_Data *data){
  start_gayTime = data->toPinLevel();
}

void partyTime(){
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
      randomDelayGenerator();
      delay(randomDelay);
}

void gayTime(){
    CRGB colours[] = {CRGB::Red, CRGB(255,128,0), CRGB::Yellow, CRGB::Green, CRGB::Blue, CRGB::Purple};   
    for(int p = 0; p < 40; p++){
      for(int i = 0; i < 6; i++){
        leds[6 * p + i] = colours[(p + 6) % 6];
      }
    }
    FastLED.show();
  
//    for(int i = 0; i < 6; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 6; i < 12; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 12; i < 18; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 18; i < 24; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 24; i < 30; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 30; i < 36; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 36; i < 42; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 42; i < 48; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 48; i < 54; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 54; i < 60; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 60; i < 66; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 66; i < 72; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 72; i < 78; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 78; i < 84; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 84; i < 90; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 90; i < 96; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 96; i < 102; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 102; i < 108; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 108; i < 114; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 114; i < 120; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 120; i < 126; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 126; i < 132; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 132; i < 136; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 136; i < 142; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 142; i < 148; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 148; i < 154; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 154; i < 160; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 160; i < 166; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 166; i < 172; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 172; i < 178; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 178; i < 184; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 184; i < 190; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 190; i < 196; i++){
//      leds[i] = CRGB::Yellow;
//    }
//    for(int i = 196; i < 202; i++){
//      leds[i] = CRGB::Green;
//    }
//    for(int i = 202; i < 208; i++){
//      leds[i] = CRGB::Blue;
//    }
//    for(int i = 214; i < 220; i++){
//      leds[i] = CRGB::Purple;
//    }
//    for(int i = 220; i < 226; i++){
//      leds[i] = CRGB::Red;
//    }
//    for(int i = 226; i < 232; i++){
//      leds[i] = CRGB(255,128,0);
//    }
//    for(int i = 232; i < 238; i++){
//      leds[i] = CRGB::Yellow;
//    }
}

void randomNumberGenerator(){
 randomNumber = random8(0,255); 
}

void randomDelayGenerator(){
  randomDelay = random8(500,2000);
}
