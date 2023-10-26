#include "../include/BaseController.h"
#include <Arduino.h>

BaseController::BaseController(int startAddress)
{
    if (startAddress <= 512)
    {
        address = startAddress;
    }
}

bool BaseController::validateValue(int value)
{
    return (value <= 255 && value >= 0);
}

