#include "src/arduino/AnalogLed.hpp"
#include "src/itf/Led.h"
#include "src/candle/Candle.hpp"
#include "src/button/Button.hpp"
#include "src/externals/dyplayer/DYPlayerArduino.h"
#include <SoftwareSerial.h>

// #define FLICKER_LED_PIN1 3
#define FLICKER_LED_PIN2 5
#define FLICKER_LED_PIN3 6
#define FLICKER_LED_PIN4 9
#define FLICKER_LED_PIN5 10
#define FLICKER_LED_PIN6 11

#define SWITCH_1 12
#define SWITCH_2 13

// arduino::AnalogLed led1{FLICKER_LED_PIN1};
arduino::AnalogLed led2{FLICKER_LED_PIN2};
arduino::AnalogLed led3{FLICKER_LED_PIN3};
arduino::AnalogLed led4{FLICKER_LED_PIN4};
arduino::AnalogLed led5{FLICKER_LED_PIN5};
arduino::AnalogLed led6{FLICKER_LED_PIN6};

// candle::Candle candle1{led1};
candle::Candle candle2{led2};
candle::Candle candle3{led3};
candle::Candle candle4{led4};
candle::Candle candle5{led5};
candle::Candle candle6{led6};

button::Button sw1{SWITCH_1};

SoftwareSerial SoftSerial(2, 3); //rx tx
DY::Player player(&SoftSerial);

unsigned int switch2Count = 0;

void setup()
{
    randomSeed(analogRead(0));
    player.begin();
    Serial.begin(9600);
    player.setVolume(30); // 50% Volume
    pinMode(14, OUTPUT);
    pinMode(SWITCH_1, INPUT);
}

void shortPress()
{
    digitalWrite(14, HIGH);
    delay(10);
    digitalWrite(14, LOW);
}

void longPress()
{
    digitalWrite(14, HIGH);
}

void release()
{
    // switch1Count = 0;
    digitalWrite(14, LOW);
}

// void check(void (*lp)(), void (*sp)(), void (*r)())
// {
//     if (digitalRead(SWITCH_1) == HIGH)
//     {
//         switch1Count++;
//         if (switch1Count > SWITCH_MAX_TIME_PRESS)
//         {
//             lp();
//         }
//         else
//         {
//             sp();
//         }
//     }
//     else
//     {
//         r();
//     }
// }

void loop()
{
    // candle1.run();
    candle2.run();
    candle3.run();
    candle4.run();
    candle5.run();
    candle6.run();

    delay(random(50, 150));

    sw1.check(longPress, shortPress, release);
    // player.playSpecified(1);
    // delay(2000);
}