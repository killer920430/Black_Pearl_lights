#include "AnalogLed.hpp"
#include "Arduino.h"

namespace arduino
{
    AnalogLed::AnalogLed(int pin) : pin(pin)
    {
        init();
    }

    void AnalogLed::init()
    {
        pinMode(pin, OUTPUT);
    }

    void AnalogLed::write(int &value)
    {
        analogWrite(pin, value);
    }
} // namespace arduino