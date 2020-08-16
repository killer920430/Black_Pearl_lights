#ifndef SRC_ARDUINO_ARDUINOPINCONTROL
#define SRC_ARDUINO_ARDUINOPINCONTROL
#include "../itf/PinControl.h"

namespace arduino
{
    class ArduinoPinControl : public itf::PinControl
    {
    public:
        void pinMode(const uint8_t &pin, const itf::mode &mode) const override;
        void digitalWrite(const uint8_t &pin, const uint8_t &val) const override;
        int digitalRead(const uint8_t &pin) const override;
        int analogRead(const uint8_t &pin) const override;
        void analogWrite(const uint8_t &pin, const int &val) const override;
    };
} // namespace arduino
#endif /* SRC_ARDUINO_ARDUINOPINCONTROL */
