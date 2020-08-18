#ifndef SRC_ARDUINO_ANALOGLED
#define SRC_ARDUINO_ANALOGLED

#include "../itf/Led.h"
#include "../itf/PinControl.h"

namespace led
{
    class AnalogLed : public itf::Led
    {
    public:
        AnalogLed(itf::PinControl &, const uint8_t);
        void write(const uint8_t &) override;

    private:
        void init();

        itf::PinControl &pinControl;
        uint8_t pin;
    };
} // namespace led
#endif /* SRC_ARDUINO_ANALOGLED */
