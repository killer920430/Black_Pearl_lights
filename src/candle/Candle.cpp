#include "Candle.hpp"
#include "Arduino.h"

namespace candle
{
    uint8_t Candle::values[] = {};

    Candle::Candle(itf::Led &led) : led(led)
    {
        generateValues();
    }

    void Candle::run()
    {
        led.write(values[index]);
        index++;
        if (index == valuesSize)
            index = 0;
    }

    void Candle::off()
    {
        led.write(0);
    }

    void Candle::generateValues()
    {
        static bool areValuesGenerated = false;
        if (!areValuesGenerated)
        {
            values[0] = random(low_value, high_value);
            for (int i = 1; i < valuesSize; ++i)
            {
                values[i] = generateValue(values[i - 1]);
            }
            areValuesGenerated = true;
        }
        index = random(0, valuesSize - 1);
    }

    unsigned int Candle::generateValue(const unsigned int &lastValue)
    {
        unsigned int value = lastValue + random(random_min_value, random_max_value);
        if (value > high_value)
        {
            return high_value;
        }
        if (value < low_value)
        {
            return low_value;
        }
        return value;
    }
} // namespace candle
