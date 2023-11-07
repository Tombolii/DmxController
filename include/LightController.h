#ifndef LightController_h
#define LightController_h

#include "../include/BaseController.h"
#include "../include/DmxAdapter.h"
// #include <Arduino.h>

class LightController : public BaseController
{
public:
  LightController(int startAddress);
  void lightGreen();
  void lightBlue();
  void lightRed();
  void lightRGB(int red, int green, int blue);

private:
  const int dimmer = 1;
  const int programs = 2;
  const int red = 3;
  const int green = 4;
  const int blue = 5;
  const int strobe = 6;
  const int lenses = 7;
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