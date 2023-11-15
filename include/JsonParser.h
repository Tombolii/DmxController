#ifndef JsonParser_h
#define JsonParser_h

#include <ArduinoJson.h>
#include "HazerState.h"

class JsonParser
{
public:
    HazerState jsonToHazerState(String json);
};

#endif