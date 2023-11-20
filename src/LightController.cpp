#include "../include/LightController.h"

LightController::LightController(int startAddress)
{
    this->address = startAddress;
}

void LightController::lightGreen()
{
    // Serial.println("Lighting green");
    dmxAdapter.write(3, 255);
    dmxAdapter.write(4, 0);
    dmxAdapter.write(5, 0);
    dmxAdapter.write(6, 255);
    dmxAdapter.write(7, 0);
    dmxAdapter.write(8, 0);
    dmxAdapter.write(9, 0);
}

void LightController::lightRed()
{
    dmxAdapter.write(3, 255); // DIMMER
    dmxAdapter.write(4, 0);   // PROGRAMME
    dmxAdapter.write(5, 255); // ROT
    dmxAdapter.write(6, 0);   // GRÜN
    dmxAdapter.write(7, 0);   // BLAU
    dmxAdapter.write(8, 0);   // STROBE
    dmxAdapter.write(9, 0);   // LINSEN
}

void LightController::lightBlue()
{
    dmxAdapter.write(3, 255);
    dmxAdapter.write(4, 0);
    dmxAdapter.write(5, 0);
    dmxAdapter.write(6, 0);
    dmxAdapter.write(7, 255);
    dmxAdapter.write(8, 0);
    dmxAdapter.write(9, 0);
}

void LightController::lightRGB(RGBState rgbState)
{
    if (validateValue(rgbState.red) && validateValue(rgbState.green) && validateValue(rgbState.blue))
    {
        setDimmer(255);
        setPrograms(0);
        setRed(rgbState.red);
        setGreen(rgbState.green);
        setBlue(rgbState.blue);
        setStrobe(0);
        setLenses(0);
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