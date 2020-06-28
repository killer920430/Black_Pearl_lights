#ifndef SRC_ARDUINO_ANALOGLED
#define SRC_ARDUINO_ANALOGLED
#include "../if/Led.h"
namespace arduino
{
    class AnalogLed : public Led
    {
    public:
        AnalogLed(int);
        void write(int &) override;

    private:
        void init();

        int pin;
    };
} // namespace arduino
#endif /* SRC_ARDUINO_ANALOGLED */
