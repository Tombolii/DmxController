#include "../include/HazerController.h"

HazerController::HazerController(int startAddress) : BaseController(startAddress){}

void HazerController::adjustFan(int level)
{
    if(validateValue(level)){
        dmxAdapter.write(fanChannel + address, level);
    }
}