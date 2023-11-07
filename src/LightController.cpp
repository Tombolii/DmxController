#include "../include/LightController.h"

LightController::LightController(int startAddress) : BaseController(startAddress)
{
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

void LightController::lightRGB(int red, int green, int blue)
{
    if (validateValue(red) && validateValue(green) && validateValue(blue))
    {
        setDimmer(255);
        setPrograms(0);
        setRed(red);
        setGreen(green);
        setBlue(blue);
        setStrobe(0);
        setLenses(0);
    }
}

void LightController::setDimmer(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + dimmer - 1, value);
    }
}

void LightController::setPrograms(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + programs -1, value);
    }
}

void LightController::setRed(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + red -1, value);
    }
}

void LightController::setGreen(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + green -1, value);
    }
}

void LightController::setBlue(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + blue -1, value);
    }
}

void LightController::setStrobe(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + strobe -1, value);
    }
}

void LightController::setLenses(int value)
{
    if (validateValue(value))
    {
        dmxAdapter.write(address + lenses -1, value);
    }
}