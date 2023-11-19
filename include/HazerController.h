#ifndef HazerController_h
#define HazerController_h

#include "BaseController.h"
#include "DmxAdapter.h"
#include "HazerState.h"

class HazerController : public BaseController
{
  public:
    HazerController(int startAddress);
    void adjustState(HazerState hazerState);

  private:
    const int volumeChannel = 1;
    const int fanChannel = 0;
    DmxAdapter dmxAdapter;
};

#endif