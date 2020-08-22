#ifndef SRC_CANNON_CANNONS
#define SRC_CANNON_CANNONS
#include "../itf/PinControl.h"
namespace cannon
{
    class Cannons
    {
    public:
        Cannons(itf::PinControl &, const uint8_t, const uint8_t, const uint8_t, const uint8_t);
        void run();

    private:
        void lightCannon(const uint8_t pin);
        void lightOff();

        itf::PinControl &pinControl;
        const uint8_t pins[4];
        const bool cannons[13][4] = {
            {false, false, false, false},
            {true, false, false, false},
            {false, true, false, false},
            {true, true, false, false},
            {false, false, true, false},
            {true, false, true, false},
            {false, true, true, false},
            {true, true, true, false},
            {false, false, false, true},
            {true, false, false, true},
            {false, true, false, true},
            {true, true, false, true},
            {false, false, true, true}};
        const unsigned int lightsOnIteration = 200;
        const unsigned int lightsOffIteration = 300;
        const unsigned int maxfIteration = 4000;
        unsigned int currentIteration = 0;
    };
} // namespace cannon
#endif /* SRC_CANNON_CANNONS */
