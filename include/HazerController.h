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
    static HazerInterval hazerInterval;
    static int startTime;
    static int duration;
    static void checkTimer();
    static void startTimer(HazerInterval hazerInterval);
    static void stopTimer();
    void adjustState(HazerState hazerState);
    

  private:
    static int volumeChannel;
    static int fanChannel;
    static int address;
    static DmxAdapter dmxAdapter;
    bool validateValue(int value);
    
};

#endif