#include "../include/HazerController.h"

HazerController::HazerController(int startAddress)
{
    HazerController::address = startAddress;
}

HazerInterval HazerController::hazerInterval = HazerInterval(0, 0, 0, 0, 0);
DmxAdapter HazerController::dmxAdapter = DmxAdapter();
int HazerController::startTime = 0;
int HazerController::duration = 0;
int HazerController::volumeChannel = 1;
int HazerController::fanChannel = 0;
int HazerController::address = 1;

void HazerController::adjustState(HazerState hazerState)
{
    if (validateValue(hazerState.fanLevel))
    {
        dmxAdapter.write(fanChannel + address, hazerState.fanLevel);
    }
    if (validateValue(hazerState.volumeLevel))
    {
        dmxAdapter.write(volumeChannel + address, hazerState.volumeLevel);
    }
}

void HazerController::checkTimer()
{
    if (millis() - HazerController::hazerInterval.startTime < HazerController::hazerInterval.duration)
    {
        if (millis() - HazerController::hazerInterval.offLastTime > HazerController::hazerInterval.offTime 
        && !HazerController::hazerInterval.hazeOn)
        {
            HazerController::hazerInterval.hazeOn = true;
            HazerController::hazerInterval.hazeLastTime = millis();
            HazerController::hazerInterval.sent = false;
        }
        else if (millis() - HazerController::hazerInterval.hazeLastTime > HazerController::hazerInterval.hazeTime 
        && HazerController::hazerInterval.hazeOn)
        {
            HazerController::hazerInterval.hazeOn = false;
            HazerController::hazerInterval.offLastTime = millis();
            HazerController::hazerInterval.sent = false;
        }

        if (!HazerController::hazerInterval.hazeOn && !HazerController::hazerInterval.sent)
        {
            dmxAdapter.write(fanChannel + address, 0);
            dmxAdapter.write(volumeChannel + address, 0);
            HazerController::hazerInterval.sent = true;
        }
        else if (HazerController::hazerInterval.hazeOn && !HazerController::hazerInterval.sent)
        {
            dmxAdapter.write(fanChannel + address, HazerController::hazerInterval.fanLevel);
            dmxAdapter.write(volumeChannel + address, HazerController::hazerInterval.volumeLevel);
            HazerController::hazerInterval.sent = true;
        }
    }
}

void HazerController::startTimer(HazerInterval hazerInterval)
{
    hazerInterval.startTime = millis();

    Serial.print("Duration: ");
    Serial.println(hazerInterval.duration);
    Serial.print("Off Time: ");
    Serial.println(hazerInterval.offTime);
    Serial.print("Haze Time: ");
    Serial.println(hazerInterval.hazeTime);
    Serial.print("Fan Level: ");
    Serial.println(hazerInterval.fanLevel);
    Serial.print("Volume Level: ");
    Serial.println(hazerInterval.volumeLevel);
    HazerController::hazerInterval = hazerInterval;
}

void HazerController::stopTimer()
{
    HazerController::hazerInterval = HazerInterval(0, 0, 0, 0, 0);
}

bool HazerController::validateValue(int value)
{
    return (value <= 255 && value >= 0);
}