#include "ArduinoPinControl.hpp"
#include "Arduino.h"

namespace arduino
{
    void ArduinoPinControl::pinMode(const uint8_t &pin, const itf::mode &mode) const
    {
        if (mode == itf::mode::input)
            ::pinMode(pin, INPUT);
        else
            ::pinMode(pin, OUTPUT);
    }

    void ArduinoPinControl::digitalWrite(const uint8_t &pin, const uint8_t &val) const
    {
        ::digitalWrite(pin, val);
    }

    int ArduinoPinControl::digitalRead(const uint8_t &pin) const
    {
        return ::digitalRead(pin);
    }

    int ArduinoPinControl::analogRead(const uint8_t &pin) const
    {
        return ::analogRead(pin);
    }

    void ArduinoPinControl::analogWrite(const uint8_t &pin, const int &val) const
    {
        ::analogWrite(pin, val);
    }
} // namespace arduino