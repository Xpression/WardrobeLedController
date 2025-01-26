#include <FastLED.h>

// The number of pixels/LEDs
#define NUM_LEDS 28

// The pin that controls the LEDs/LED data pin
#define LED_PIN 4

// The first pin out of a consequtive sequence that is connected to a magnetic switch.
// These switches indicate whether a door is open or closed
#define DOOR_PIN 5

// The number of doors/switches
#define NUM_DOORS 2

#define OPEN 1
#define CLOSED 0

CRGB leds[NUM_LEDS];

void setup() {

  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, LED_PIN, BRG>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  //FastLED.setTemperature(Tungsten100W);
  FastLED.setTemperature(Tungsten40W);

  // Enable pullups for magnetic door switches. Required to remove noise and avoid flickering.
  for (int i = 0; i < NUM_DOORS; i++)
  {
    pinMode(DOOR_PIN + i, INPUT_PULLUP);
  }

  // Initially turn of the LEDs
  for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
    }
}

bool lastState = CLOSED;
void loop() {

  bool newState = anyDoorOpen();

  if (newState != lastState)
  {
    // Debounce by waiting a bit
    delay(200);

    CRGB color = CRGB::Black;
    if (newState == OPEN)
    {
      color = CRGB(255, 147, 41);
    }
    
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = color;//CRGB(0xE1A024);//CRGB::FairyLight;//
    }
    
    FastLED.show();
  }
  
  lastState = newState;

  // just wait a bit
  delay(100);
}

// Checks whether a specific door is open
bool isDoorOpen(int pinNumber)
{
  return digitalRead(pinNumber);
}

// Checks whether any door is open
bool anyDoorOpen()
{
  for (int i = 0; i < NUM_DOORS; i++)
  {
    if (isDoorOpen(DOOR_PIN + i))
    {
      return true;
    }
  }

  return false;
}
