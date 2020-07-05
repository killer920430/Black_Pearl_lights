#include "src/arduino/AnalogLed.hpp"
#include "src/itf/Led.h"
#include "src/candle/Candle.hpp"

#define FLICKER_LED_PIN0 3
#define FLICKER_LED_PIN1 5
#define FLICKER_LED_PIN2 6
#define FLICKER_LED_PIN3 9
#define FLICKER_LED_PIN4 10
#define FLICKER_LED_PIN5 11

arduino::AnalogLed led1{FLICKER_LED_PIN0};

candle::Candle candle1{led1};

void setup()
{
    randomSeed(analogRead(0));
}

void loop()
{
    candle1.run();
    delay(100); // the delay between changes
}