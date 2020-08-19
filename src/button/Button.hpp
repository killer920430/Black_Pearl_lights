#ifndef SRC_SWITCH_SWITCH
#define SRC_SWITCH_SWITCH

#include "../itf/PinControl.h"
namespace button
{
#define SWITCH_MAX_TIME_PRESS 4
    class Button
    {
    public:
        Button(const itf::PinControl &pinControl, const uint8_t, void (*longPress)(), void (*shortPress)(), const int maxCountPress = 4);
        void check();

    private:
        const itf::PinControl &pinControl;
        const uint8_t pin;
        void (*longPress)();
        void (*shortPress)();
        const unsigned int maxCountPress;
        unsigned int count = 0;
    };
} // namespace button
#endif /* SRC_SWITCH_SWITCH */
