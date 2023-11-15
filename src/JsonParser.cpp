#include "../include/JsonParser.h"

HazerState JsonParser::jsonToHazerState(String json)
{
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (error)
    {
        Serial.print(F("Failed to parse JSON: "));
        Serial.println(error.c_str());
        return HazerState(0, 0);
    }
    HazerState hazerState(
        doc["fanLevel"].as<int>(),
        doc["volumeLevel"].as<int>());

    return hazerState;
}
