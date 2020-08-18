#include "Candle.hpp"
#include "Arduino.h"

namespace candle
{
    Candle::Candle(itf::Led &led) : led(led)
    {
        value = random(low_value, high_value);
    }

    void Candle::run()
    {
        led.write(value);
        value += random(random_min_value, random_max_value);
        if (value > high_value)
        {
            value = high_value;
        }
        if (value < low_value)
        {
            value = low_value;
        }
    }
} // namespace candle
