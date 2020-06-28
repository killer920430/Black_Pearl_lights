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
        void generateTimeForLow();
        void generateTimeForHigh();
        void generateTimeForSpeed();
        long getHoldTime();
        long getPauseTime();
        void waitMicroseconds(const int &);
        void waitMiliseconds(const long &);

        itf::Led &led;
        int candle_random_low_start = 0;
        int candle_random_low_end = 0;
        int candle_random_high = 0;
        int candle_random_speed_start = 0;
        int candle_random_speed_end = 0;
    };
} // namespace candle
#endif /* SRC_CANDLE_CANDLE */
