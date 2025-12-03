#include "../include/LightController.h"

LightController::LightController(int startAddress)
{
    this->address = startAddress;
}

void LightController::lightRGB(RGBState rgbState)
{
    if (validateValue(rgbState.red) && validateValue(rgbState.green) && validateValue(rgbState.blue) && validateValue(rgbState.dimmer))
    {
        setDimmer(rgbState.dimmer);
        setPrograms(0);
        setRed(rgbState.red);
        setGreen(rgbState.green);
        setBlue(rgbState.blue);
        setStrobe(0);
        setLenses(0);
    }
}

void LightController::startPreset(LightPreset preset)
{
    int value = getProgram(preset.presetId);
    if (value != 0)
    {
        setDimmer(255);
        setPrograms(value);
        setRed(0);
        setGreen(0);
        setBlue(0);
        setStrobe(0);
        setLenses(0);
    }
}

int LightController::getProgram(int preset)
{
    switch (preset)
    {
    case 11:
        // MUSIC MIC
        return 252;
    case 9:
        // RANDOM STROBE
        return 220;
    default:
        return 0;
    }
}

void LightController::setDimmer(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + dimmer, value);
    }
}

void LightController::setPrograms(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + programs, value);
    }
}

void LightController::setRed(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + red, value);
    }
}

void LightController::setGreen(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + green, value);
    }
}

void LightController::setBlue(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + blue, value);
    }
}

void LightController::setStrobe(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + strobe, value);
    }
}

void LightController::setLenses(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + lenses, value);
    }
}

bool LightController::validateValue(int value)
{
    return (value <= 255 && value >= 0);
}