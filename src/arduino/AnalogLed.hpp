#ifndef SRC_ARDUINO_ANALOGLED
#define SRC_ARDUINO_ANALOGLED
#include "../if/Led.h"
namespace arduino
{
    class AnalogLed : public Led
    {
    public:
        AnalogLed();
        AnalogLed(int);
        void init();
        void write(int &);

    private:
        int pin;
    };
} // namespace arduino
#endif /* SRC_ARDUINO_ANALOGLED */
