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
        static const int low_value = 90;
        static const int high_value = 180;
        static const int random_min_value = -30;
        static const int random_max_value = 30;

        itf::Led &led;
        int value;
    };
} // namespace candle
#endif /* SRC_CANDLE_CANDLE */
