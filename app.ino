#include "src/arduino/AnalogLed.hpp"
#include "src/itf/Led.h"
#include "src/candle/Candle.hpp"

#define FLICKER_LED_PIN0 3
#define FLICKER_LED_PIN1 5
#define FLICKER_LED_PIN2 6
#define FLICKER_LED_PIN3 9
#define FLICKER_LED_PIN4 10
#define FLICKER_LED_PIN5 11

void setup() {}

// int flicker_random_low_start = 0;
// int flicker_random_low_end = 0;
// int flicker_random_high = 0;
// int flicker_random_speed_start = 0;
// int flicker_random_speed_end = 0;

arduino::AnalogLed led1{FLICKER_LED_PIN0};
candle::Candle candle1{led1};

void loop()
{
    candle1.run();
}