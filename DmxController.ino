#include <DmxSimple.h>
#include "./include/LightController.h"
#include "./include/HazerController.h"
LightController lightController(3);
HazerController hazerController(1);

void setup()
{
  Serial.begin(9600);
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  DmxSimple.maxChannel(20);
}

void loop()
{
  lightController.lightRGB(100, 100, 100);
  delay(10000);
  lightController.lightGreen();
  delay(10000);
  /* hazerController.lightRed();
   delay(1000);
   hazerController.lightBlue();
   delay(1000); */
}
