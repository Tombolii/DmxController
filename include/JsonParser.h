#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "HazerState.h"
#include "HazerInterval.h"
#include "RGBState.h"
#include "LightPreset.h"

class JsonParser
{
public:
    HazerState jsonToHazerState(String json);
    HazerInterval jsonToHazerInterval(String json);
    RGBState jsonToRGBState(String json);
    LightPreset jsonToLightPreset(String json);
};

#endif