#ifndef LightController_h
#define LightController_h

#include "BaseController.h"
#include "DmxAdapter.h"
#include "RGBState.h"
#include "LightPreset.h"

class LightController
{
public:
  LightController(int startAddress);
  void lightRGB(RGBState rgbState);
  void startPreset(LightPreset preset);

private:
  const int dimmer = 0;
  const int programs = 1;
  const int red = 2;
  const int green = 3;
  const int blue = 4;
  const int strobe = 5;
  const int lenses = 6;
  int address;
  DmxAdapter dmxAdapter;

  void setDimmer(int value);
  void setPrograms(int value);
  void setRed(int value);
  void setGreen(int value);
  void setBlue(int value);
  void setStrobe(int value);
  void setLenses(int value);
  bool validateValue(int value);
  int getProgram(int preset);
};

#endif