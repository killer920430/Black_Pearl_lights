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

    private:
        static constexpr uint8_t low_value = 90;
        static constexpr uint8_t high_value = 180;
        static constexpr uint8_t random_min_value = -30;
        static constexpr uint8_t random_max_value = 30;

        itf::Led &led;
        uint8_t value;
    };
} // namespace candle
#endif /* SRC_CANDLE_CANDLE */
