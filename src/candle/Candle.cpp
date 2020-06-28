#include "Candle.hpp"
#include "CandleConstants.h"
#include "Arduino.h"

namespace candle
{
    Candle::Candle(itf::Led &led) : led(led) {}

    void Candle::run()
    {
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
            led.write(i);
            delayMicroseconds(flicker_random_speed_start);
        }

        // hold
        delay(random(flicker_hold_min, flicker_hold_max));

        // high -> low
        for (int i = flicker_random_high; i >= flicker_random_low_end; i--)
        {
            led.write(i);
            delayMicroseconds(flicker_random_speed_end);
        }

        // pause
        delay(random(flicker_pause_min, flicker_pause_max));
    }
} // namespace candle
