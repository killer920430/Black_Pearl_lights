#ifndef SRC_ARDUINO_ANALOGLED
#define SRC_ARDUINO_ANALOGLED

#include "../itf/Led.h"
#include "../itf/PinControl.h"

namespace led
{
    class AnalogLed : public itf::Led
    {
    public:
        AnalogLed(itf::PinControl &, int);
        void write(int &) override;

    private:
        void init();

        itf::PinControl &pinControl;
        int pin;
    };
} // namespace led
#endif /* SRC_ARDUINO_ANALOGLED */
