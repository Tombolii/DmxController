#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "HazerState.h"
#include "RGBState.h"

class JsonParser
{
public:
    HazerState jsonToHazerState(String json);
    RGBState jsonToRGBState(String json);
};

#endif