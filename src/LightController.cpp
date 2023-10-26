#include "../include/LightController.h"
#include <DmxSimple.h>
#include <Arduino.h>



LightController::LightController(int startAddress) : BaseController(startAddress)
{
    // set all values initally to 0
    setDimmer(0);
    setPrograms(0);
    setRed(0);
    setGreen(0);
    setBlue(0);
    setStrobe(0);
    setLenses(0);
}

void LightController::lightGreen()
{
    DmxSimple.write(3, 255);
    DmxSimple.write(4, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 255);
    DmxSimple.write(7, 0);
    DmxSimple.write(8, 0);
    DmxSimple.write(9, 0);
}

void LightController::lightRed()
{
    DmxSimple.write(3, 255); // DIMMER
    DmxSimple.write(4, 0);   // PROGRAMME
    DmxSimple.write(5, 255); // ROT
    DmxSimple.write(6, 0);   // GRÜN
    DmxSimple.write(7, 0);   // BLAU
    DmxSimple.write(8, 0);   // STROBE
    DmxSimple.write(9, 0);   // LINSEN
}

void LightController::lightBlue()
{
    DmxSimple.write(3, 255);
    DmxSimple.write(4, 0);
    DmxSimple.write(5, 0);
    DmxSimple.write(6, 0);
    DmxSimple.write(7, 255);
    DmxSimple.write(8, 0);
    DmxSimple.write(9, 0);
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
        DmxSimple.write(address + dimmer -1, value);
    }
}

void LightController::setPrograms(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + programs -1, value);
    }
}

void LightController::setRed(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + red -1, value);
    }
}

void LightController::setGreen(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + green -1, value);
    }
}

void LightController::setBlue(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + blue -1, value);
    }
}

void LightController::setStrobe(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + strobe -1, value);
    }
}

void LightController::setLenses(int value)
{
    if (validateValue(value))
    {
        DmxSimple.write(address + lenses -1, value);
    }
}
