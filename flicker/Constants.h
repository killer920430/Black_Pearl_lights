// the start of the flicker (low)
const static int flicker_low_min = 200;
const static int flicker_low_max = 240;

// the end value of the flicker (high)
const static int flicker_high_min = 230;
const static int flicker_high_max = 256;

// delay between each low-high-low cycle
// low->high |flicker_hold| high->low
const static int flicker_hold_min = 40; // milliseconds
const static int flicker_hold_max = 80; // milliseconds

// delay after each low-high-low cycle
// low->high->low |flicker_pause| low->high...
const static int flicker_pause_min = 100; // milliseconds
const static int flicker_pause_max = 200; // milliseconds

// delay low to high and high to low cycle
const static int flicker_speed_min = 900;  // microseconds
const static int flicker_speed_max = 1000; // microseconds