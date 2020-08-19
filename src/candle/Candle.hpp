#ifndef SRC_CANDLE_CANDLE
#define SRC_CANDLE_CANDLE
#include "../itf/Led.h"
#include "Candle.hpp"

namespace candle
{
    class Candle
    {
    public:
        Candle(itf::Led &);
        void run();
        void off();

    private:
        void generateValues();
        unsigned int generateValue(const unsigned int &lastValue);
        static constexpr uint8_t valuesSize{30};
        static constexpr uint8_t low_value = 70;
        static constexpr uint8_t high_value = 180;
        static constexpr int8_t random_min_value = -50;
        static constexpr uint8_t random_max_value = 50;

        static uint8_t values[valuesSize];
        itf::Led &led;
        uint8_t index = 0;
    };
} // namespace candle
#endif /* SRC_CANDLE_CANDLE */
