#include "Button.hpp"
// #include "Arduino.h"

namespace button
{
    Button::Button(const itf::PinControl &pinControl,
                   const uint8_t pin,
                   void (*longPress)(),
                   void (*shortPress)(),
                   const int maxCountPress) : pinControl(pinControl),
                                              pin(pin),
                                              longPress(longPress),
                                              shortPress(shortPress),
                                              maxCountPress(maxCountPress)
    {
    }

    void Button::check()
    {
        if (pinControl.digitalRead(pin))
        {
            count++;
        }
        else if (count > 0)
        {
            if (count > maxCountPress)
                longPress();
            else
                shortPress();
            count = 0;
        }
    }
} // namespace button