#ifndef SRC_ITF_PINCONTROL
#define SRC_ITF_PINCONTROL
#include "stdint.h"

namespace itf
{
    enum mode
    {
        input,
        output
    };

    class PinControl
    {
    public:
        virtual void pinMode(const uint8_t &pin, const mode &mode) const = 0;
        virtual void digitalWrite(const uint8_t &pin, const uint8_t &val) const = 0;
        virtual int digitalRead(const uint8_t &pin) const = 0;
        virtual int analogRead(const uint8_t &pin) const = 0;
        virtual void analogWrite(const uint8_t &pin, const int &val) const = 0;
    };
} // namespace itf
#endif /* SRC_ITF_PINCONTROL */
