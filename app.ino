#include "src/arduino/AnalogLed.hpp"
#include "src/arduino/ArduinoPinControl.hpp"
#include "src/button/Button.hpp"
#include "src/candle/Candle.hpp"
#include "src/externals/dyplayer/DYPlayerArduino.h"
#include "src/itf/Led.h"
#include <SoftwareSerial.h>

#define AUDIO_RX 2
#define AUDIO_TX 3

// #define FLICKER_LED_PIN1 3
#define FLICKER_LED_PIN2 5
#define FLICKER_LED_PIN3 6
#define FLICKER_LED_PIN4 9
#define FLICKER_LED_PIN5 10
#define FLICKER_LED_PIN6 11

#define SWITCH_1 12
#define SWITCH_2 13

arduino::ArduinoPinControl pinControl{};

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

SoftwareSerial SoftSerial(AUDIO_RX, AUDIO_TX);
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
    digitalWrite(14, LOW);
}
button::Button sw1{pinControl, SWITCH_1, longPress, shortPress, release};

void loop()
{
    // candle1.run();
    candle2.run();
    candle3.run();
    candle4.run();
    candle5.run();
    candle6.run();

    delay(random(50, 150));

    sw1.check();
    // player.playSpecified(1);
    // delay(2000);
}