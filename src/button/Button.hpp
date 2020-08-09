#ifndef SRC_SWITCH_SWITCH
#define SRC_SWITCH_SWITCH

#include "../itf/PinControl.h"
namespace button
{
#define SWITCH_MAX_TIME_PRESS 4
    class Button
    {
    public:
        Button(itf::PinControl &pinControl, uint8_t, void (*longPress)(), void (*shortPress)(), void (*release)(), int maxCountPress = 4);
        void check();

    private:
        itf::PinControl &pinControl;
        const uint8_t pin;
        void (*longPress)();
        void (*shortPress)();
        void (*release)();
        unsigned int maxCountPress = 4;
        unsigned int count = 0;
    };
} // namespace button
#endif /* SRC_SWITCH_SWITCH */
