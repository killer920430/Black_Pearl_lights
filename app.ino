#include "src/arduino/AnalogLed.hpp"
#include "src/itf/Led.h"
#include "src/candle/Candle.hpp"

#define FLICKER_LED_PIN1 3
#define FLICKER_LED_PIN2 5
#define FLICKER_LED_PIN3 6
#define FLICKER_LED_PIN4 9
#define FLICKER_LED_PIN5 10
#define FLICKER_LED_PIN6 11

arduino::AnalogLed led1{FLICKER_LED_PIN1};
arduino::AnalogLed led2{FLICKER_LED_PIN2};
arduino::AnalogLed led3{FLICKER_LED_PIN3};
arduino::AnalogLed led4{FLICKER_LED_PIN4};
arduino::AnalogLed led5{FLICKER_LED_PIN5};
arduino::AnalogLed led6{FLICKER_LED_PIN6};

candle::Candle candle1{led1};
candle::Candle candle2{led2};
candle::Candle candle3{led3};
candle::Candle candle4{led4};
candle::Candle candle5{led5};
candle::Candle candle6{led6};

void setup()
{
    randomSeed(analogRead(0));
}

void loop()
{
    candle1.run();
    candle2.run();
    candle3.run();
    candle4.run();
    candle5.run();
    candle6.run();
    delay(100); // the delay between changes
}