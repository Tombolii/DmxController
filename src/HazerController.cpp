#include "../include/HazerController.h"

HazerController::HazerController(int startAddress) : BaseController(startAddress){}

void HazerController::adjustState(HazerState hazerState)
{
    if(validateValue(hazerState.fanLevel)){
        dmxAdapter.write(fanChannel + address, hazerState.fanLevel);
    }
    if(validateValue(hazerState.volumeLevel)){
        dmxAdapter.write(volumeChannel + address, hazerState.volumeLevel);
    }
}