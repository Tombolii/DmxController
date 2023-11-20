#ifndef HazerController_h
#define HazerController_h

#include "BaseController.h"
#include "DmxAdapter.h"
#include "HazerState.h"
#include "HazerInterval.h"

class HazerController
{
  public:
    HazerController(int startAddress);
    void adjustState(HazerState hazerState);
    static void checkTimer();
    static void startTimer(HazerInterval hazerInterval);
    static HazerInterval hazerInterval;
    static int startTime;
    static int duration;

  private:
    static int volumeChannel;
    static int fanChannel;
    static int address;
    static DmxAdapter dmxAdapter;
    bool validateValue(int value);
    
};

#endif