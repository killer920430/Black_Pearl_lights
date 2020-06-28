namespace candle
{
    // the start of the candle (low)
    const static int candle_low_min = 200;
    const static int candle_low_max = 240;

    // the end value of the candle (high)
    const static int candle_high_min = 230;
    const static int candle_high_max = 256;

    // delay between each low-high-low cycle
    // low->high |candle_hold| high->low
    const static int candle_hold_min = 40; // milliseconds
    const static int candle_hold_max = 80; // milliseconds

    // delay after each low-high-low cycle
    // low->high->low |candle_pause| low->high...
    const static int candle_pause_min = 100; // milliseconds
    const static int candle_pause_max = 200; // milliseconds

    // delay low to high and high to low cycle
    const static int candle_speed_min = 900;  // microseconds
    const static int candle_speed_max = 1000; // microseconds
} // namespace candle