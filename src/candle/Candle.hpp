#ifndef SRC_CANDLE_CANDLE
#define SRC_CANDLE_CANDLE
#include "Candle.hpp"
#include "../itf/Led.h"

namespace candle
{
    class Candle
    {
    public:
        Candle(itf::Led &);
        void run();

    private:
        itf::Led &led;
        int flicker_random_low_start = 0;
        int flicker_random_low_end = 0;
        int flicker_random_high = 0;
        int flicker_random_speed_start = 0;
        int flicker_random_speed_end = 0;
    };
} // namespace candle
#endif /* SRC_CANDLE_CANDLE */
