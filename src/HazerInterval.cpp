#include "../include/HazerInterval.h"

HazerInterval::HazerInterval(int duration, int offTime, int hazeTime, int fanLevel, 
    int volumeLevel)
{
    this->duration = duration;
    this->offTime = offTime;
    this->hazeTime = hazeTime;
    this->hazeOn = false;
    this->fanLevel = fanLevel;
    this->volumeLevel = volumeLevel;
    this->hazeLastTime = 0;
    this->offLastTime = 0;
}