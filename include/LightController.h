#ifndef LightController_h
#define LightController_h

#include "BaseController.h"
#include "DmxAdapter.h"
# include "RGBState.h"

class LightController : public BaseController
{
public:
  LightController(int startAddress);
  void lightGreen();
  void lightBlue();
  void lightRed();
  void lightRGB(RGBState rgbState);

private:
  const int dimmer = 0;
  const int programs = 1;
  const int red = 2;
  const int green = 3;
  const int blue = 4;
  const int strobe = 5;
  const int lenses = 6;
  const int address = 3;
  DmxAdapter dmxAdapter;

  void setDimmer(int value);
  void setPrograms(int value);
  void setRed(int value);
  void setGreen(int value);
  void setBlue(int value);
  void setStrobe(int value);
  void setLenses(int value);
};

#endif