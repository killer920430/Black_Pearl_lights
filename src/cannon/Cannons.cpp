#include "Cannons.hpp"
#include "arduino.h"

namespace cannon
{
    Cannons::Cannons(itf::PinControl &pinControl,
                     const uint8_t controlPin1,
                     const uint8_t controlPin2,
                     const uint8_t controlPin3,
                     const uint8_t controlPin4) : pinControl(pinControl),
                                                  pins{controlPin1,
                                                       controlPin2,
                                                       controlPin3,
                                                       controlPin4}
    {
        pinControl.pinMode(pins[0], itf::mode::output);
        pinControl.pinMode(pins[1], itf::mode::output);
        pinControl.pinMode(pins[2], itf::mode::output);
        pinControl.pinMode(pins[3], itf::mode::output);
    }

    void Cannons::run()
    {
        for (uint8_t i = 0; i < 13; i++)
        {
            lightCannon(i);
        }
    }

    void Cannons::lightCannon(const uint8_t id)
    {
        pinControl.digitalWrite(pins[0], cannons[id][0]);
        pinControl.digitalWrite(pins[1], cannons[id][1]);
        pinControl.digitalWrite(pins[2], cannons[id][2]);
        pinControl.digitalWrite(pins[3], cannons[id][3]);
    }
} // namespace cannon