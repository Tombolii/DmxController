#ifndef HazerController_h
#define HazerController_h

#include "../include/BaseController.h"
#include "../include/DmxAdapter.h"

class HazerController : public BaseController
{
  public:
    HazerController(int startAddress);
    void adjustFan(int level);

  private:
    const int volumeChannel = 1;
    const int fanChannel = 2;
    DmxAdapter dmxAdapter;
};

#endif