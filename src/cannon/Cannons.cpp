#include "Cannons.hpp"
#include "arduino.h"

namespace cannon
{
    Cannons::Cannons(itf::PinControl &pinControl,
                     const uint8_t controlPin1,
                     const uint8_t controlPin2,
                     const uint8_t controlPin3,
                     const uint8_t controlPin4,
                     void (*playTrack)(uint8_t)) : pinControl(pinControl),
                                                   pins{controlPin1,
                                                        controlPin2,
                                                        controlPin3,
                                                        controlPin4},
                                                   playTrack(playTrack)
    {
        pinControl.pinMode(pins[0], itf::mode::output);
        pinControl.pinMode(pins[1], itf::mode::output);
        pinControl.pinMode(pins[2], itf::mode::output);
        pinControl.pinMode(pins[3], itf::mode::output);
        lightOff();
    }

    void Cannons::run()
    {
        if (currentIteration == 0)
            playTrack(random(1, 3));
        if (currentIteration == lightsOnIteration)
            lightCannon(random(0, 14));
        else if (currentIteration == lightsOffIteration)
            lightOff();
        else if (currentIteration >= maxfIteration)
        {
            currentIteration = 0;
            maxfIteration = random(lightsMaxIterationMinRange, lightsMaxIterationMaxRange);
            return;
        }
        ++currentIteration;
    }

    void Cannons::off()
    {
        lightOff();
    }

    void Cannons::lightCannon(const uint8_t id)
    {
        pinControl.digitalWrite(pins[0], cannons[id][0]);
        pinControl.digitalWrite(pins[1], cannons[id][1]);
        pinControl.digitalWrite(pins[2], cannons[id][2]);
        pinControl.digitalWrite(pins[3], cannons[id][3]);
    }

    void Cannons::lightOff()
    {
        pinControl.digitalWrite(pins[0], 1);
        pinControl.digitalWrite(pins[1], 1);
        pinControl.digitalWrite(pins[2], 1);
        pinControl.digitalWrite(pins[3], 1);
    }
} // namespace cannon