#include "Button.hpp"
#include "Arduino.h"

namespace button
{
    Button::Button(int pin, void (*longPress)(), void (*shortPress)(), void (*release)(), int maxCountPress) : pin(pin),
                                                                                                               longPress(longPress),
                                                                                                               shortPress(shortPress),
                                                                                                               release(release),
                                                                                                               maxCountPress(maxCountPress)
    {
    }

    void Button::check()
    {
        if (digitalRead(pin) == HIGH)
        {
            count++;
            if (count > maxCountPress)
            {
                longPress();
            }
            else
            {
                shortPress();
            }
        }
        else
        {
            count = 0;
            release();
        }
    }
} // namespace button