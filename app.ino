#include "src/arduino/ArduinoPinControl.hpp"
#include "src/button/Button.hpp"
#include "src/candle/Candle.hpp"
#include "src/cannon/Cannons.hpp"
#include "src/externals/dyplayer/DYPlayerArduino.h"
#include "src/itf/Led.h"
#include "src/led/AnalogLed.hpp"
#include <SoftwareSerial.h>

#define AUDIO_RX 2
#define AUDIO_TX 3

#define FLICKER_LED_PIN1 5
#define FLICKER_LED_PIN2 6
#define FLICKER_LED_PIN3 9
#define FLICKER_LED_PIN4 10
#define FLICKER_LED_PIN5 11

#define SWITCH_1 12
#define SWITCH_2 13

#define CANNON_PIN_1 A0
#define CANNON_PIN_2 A1
#define CANNON_PIN_3 A2
#define CANNON_PIN_4 A3

arduino::ArduinoPinControl pinControl{};

led::AnalogLed led1{pinControl, FLICKER_LED_PIN1};
led::AnalogLed led2{pinControl, FLICKER_LED_PIN2};
led::AnalogLed led3{pinControl, FLICKER_LED_PIN3};
led::AnalogLed led4{pinControl, FLICKER_LED_PIN4};
led::AnalogLed led5{pinControl, FLICKER_LED_PIN5};

candle::Candle candle1{led1};
candle::Candle candle2{led2};
candle::Candle candle3{led3};
candle::Candle candle4{led4};
candle::Candle candle5{led5};

#define VOLUME_MAX 30
#define VOLUME_MIN 1
#define VOLUME_STEEP 3
SoftwareSerial SoftSerial(AUDIO_RX, AUDIO_TX);
DY::Player player(&SoftSerial);

uint8_t volume = VOLUME_MAX / 2;

bool lightsOn = true;
bool cannonsOn = true;
uint8_t candleIteration = 0;
uint8_t candleMaxIteration = 50;

void setup()
{
    randomSeed(analogRead(0));
    player.begin();
    Serial.begin(9600);
    player.setVolume(30); // 50% Volume
    pinMode(14, OUTPUT);
    pinMode(SWITCH_1, INPUT);
}

void increaseVolume()
{
    if (volume < VOLUME_MAX)
    {
        volume = volume + VOLUME_STEEP;
        if (volume > VOLUME_MAX)
            volume = VOLUME_MAX;
        player.setVolume(volume);
    }
}

void decreseVolume()
{
    if (volume > VOLUME_MIN)
    {
        volume = volume - VOLUME_STEEP;
        if (volume < VOLUME_MIN)
            volume = VOLUME_MIN;
        player.setVolume(volume);
    }
}

void toogleLight()
{
    if (lightsOn)
        lightsOn = false;
    else
        lightsOn = true;
}

void toogleCannons()
{
    if (cannonsOn)
        cannonsOn = false;
    else
        cannonsOn = true;
}

void playTrack(uint8_t trackId)
{
    player.playSpecified(trackId);
}

button::Button sw1{pinControl, SWITCH_2, toogleLight, increaseVolume, 3000};
button::Button sw2{pinControl, SWITCH_1, toogleCannons, decreseVolume, 3000};

cannon::Cannons cannons{
    pinControl,
    CANNON_PIN_1,
    CANNON_PIN_2,
    CANNON_PIN_3,
    CANNON_PIN_4,
    playTrack};

void loop()
{
    if (lightsOn)
    {
        if (candleIteration == 0)
        {
            candle1.run();
            candle2.run();
            candle3.run();
            candle4.run();
            candle5.run();
            ++candleIteration;
        }
        else if (candleIteration == candleMaxIteration)
        {
            candleIteration = 0;
            candleMaxIteration = random(30, 55);
        }
        else
            ++candleIteration;
    }
    else
    {
        candle1.off();
        candle2.off();
        candle3.off();
        candle4.off();
        candle5.off();
    }

    if (cannonsOn)
        cannons.run();
    else
        cannons.off();

    sw1.check();
    sw2.check();
}