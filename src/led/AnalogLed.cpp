#include "AnalogLed.hpp"

namespace led
{
    AnalogLed::AnalogLed(itf::PinControl &pinControl, const uint8_t pin) : pinControl(pinControl), pin(pin)
    {
        init();
    }

    void AnalogLed::init()
    {
        pinControl.pinMode(pin, itf::mode::output);
    }

    void AnalogLed::write(const uint8_t &value)
    {
        pinControl.analogWrite(pin, value);
    }
} // namespace led