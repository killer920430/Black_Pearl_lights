#include "Button.hpp"
// #include "Arduino.h"

namespace button
{
    Button::Button(itf::PinControl &pinControl,
                   uint8_t pin,
                   void (*longPress)(),
                   void (*shortPress)(),
                   void (*release)(),
                   int maxCountPress) : pinControl(pinControl),
                                        pin(pin),
                                        longPress(longPress),
                                        shortPress(shortPress),
                                        release(release),
                                        maxCountPress(maxCountPress)
    {
    }

    void Button::check()
    {
        if (pinControl.digitalRead(pin))
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