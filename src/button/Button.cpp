#include "Button.hpp"
#include "Arduino.h"

namespace button
{
    Button::Button(int pin) : pin(pin)
    {
    }

    void Button::check(void (*lp)(), void (*sp)(), void (*r)())
    {
        if (digitalRead(pin) == HIGH)
        {
            switch1Count++;
            if (switch1Count > SWITCH_MAX_TIME_PRESS)
            {
                lp();
            }
            else
            {
                sp();
            }
        }
        else
        {
            switch1Count = 0;
            r();
        }
    }
} // namespace button