#include "Candle.hpp"
#include "CandleConstants.h"
#include "Arduino.h"

namespace candle
{
    Candle::Candle(itf::Led &led) : led(led) {}

    void Candle::run()
    {
        generateTimeForLow();
        generateTimeForHigh();
        generateTimeForSpeed();

        // low -> high
        for (int i = candle_random_low_start; i < candle_random_high; i++)
        {
            led.write(i);
            waitMicroseconds(candle_random_speed_start);
        }

        // hold
        waitMiliseconds(getHoldTime());

        // high -> low
        for (int i = candle_random_high; i >= candle_random_low_end; i--)
        {
            led.write(i);
            waitMicroseconds(candle_random_speed_end);
        }

        // pause
        waitMiliseconds(getPauseTime());
    }

    void Candle::generateTimeForLow()
    {
        candle_random_low_start = random(candle_low_min, candle_low_max);
        candle_random_low_end = random(candle_low_min, candle_low_max);
    }

    void Candle::generateTimeForHigh()
    {
        candle_random_high = random(candle_high_min, candle_high_max);
    }

    void Candle::generateTimeForSpeed()
    {
        candle_random_speed_start = random(candle_speed_min, candle_speed_max);
        candle_random_speed_end = random(candle_speed_min, candle_speed_max);
    }

    long Candle::getHoldTime()
    {
        return random(candle_hold_min, candle_hold_max);
    }

    long Candle::getPauseTime()
    {
        return random(candle_pause_min, candle_pause_max);
    }

    void Candle::waitMicroseconds(const int &microSeconds)
    {
        delayMicroseconds(microSeconds);
    }

    void Candle::waitMiliseconds(const long &miliSeconds)
    {
        delay(miliSeconds);
    }
} // namespace candle
