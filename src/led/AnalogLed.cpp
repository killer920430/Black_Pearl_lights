#include "AnalogLed.hpp"
// #include "Arduino.h"

namespace led
{
    AnalogLed::AnalogLed(itf::PinControl &pinControl, int pin) : pinControl(pinControl), pin(pin)
    {
        init();
    }

    void AnalogLed::init()
    {
        pinControl.pinMode(pin, itf::mode::output);
    }

    void AnalogLed::write(int &value)
    {
        pinControl.analogWrite(pin, value);
    }
} // namespace led