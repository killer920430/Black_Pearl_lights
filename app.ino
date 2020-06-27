#include "flicker/Constants.h"
#include "src/arduino/AnalogLed.hpp"
#include "src/if/Led.h"

#define FLICKER_LED_PIN0 3
#define FLICKER_LED_PIN1 5
#define FLICKER_LED_PIN2 6
#define FLICKER_LED_PIN3 9
#define FLICKER_LED_PIN4 10
#define FLICKER_LED_PIN5 11

void setup()
{
    pinMode(FLICKER_LED_PIN0, OUTPUT);
}

int flicker_random_low_start = 0;
int flicker_random_low_end = 0;
int flicker_random_high = 0;
int flicker_random_speed_start = 0;
int flicker_random_speed_end = 0;
arduino::AnalogLed led1{};

void loop()
{
    Led &led2 = led1;
    led1.init();
    // random time for low
    flicker_random_low_start = random(flicker_low_min, flicker_low_max);
    flicker_random_low_end = random(flicker_low_min, flicker_low_max);

    // random time for high
    flicker_random_high = random(flicker_high_min, flicker_high_max);

    // random time for speed
    flicker_random_speed_start = random(flicker_speed_min, flicker_speed_max);
    flicker_random_speed_end = random(flicker_speed_min, flicker_speed_max);

    // low -> high
    for (int i = flicker_random_low_start; i < flicker_random_high; i++)
    {
        analogWrite(FLICKER_LED_PIN0, i);
        delayMicroseconds(flicker_random_speed_start);
    }

    // hold
    delay(random(flicker_hold_min, flicker_hold_max));

    // high -> low
    for (int i = flicker_random_high; i >= flicker_random_low_end; i--)
    {
        analogWrite(FLICKER_LED_PIN0, i);
        delayMicroseconds(flicker_random_speed_end);
    }

    // pause
    delay(random(flicker_pause_min, flicker_pause_max));
}