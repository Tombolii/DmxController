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

HazerInterval JsonParser::jsonToHazerInterval(String json)
{
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (error)
    {
        Serial.print(F("Failed to parse JSON: "));
        Serial.println(error.c_str());
        return HazerInterval(0, 0, 0, 0, 0);
    }

    HazerInterval hazerInterval(
        doc["duration"].as<int>() * 1000,
        doc["offTime"].as<int>() * 1000,
        doc["hazeTime"].as<int>() * 1000,
        doc["fanLevel"].as<int>(),
        doc["volumeLevel"].as<int>());

    return hazerInterval;
}

RGBState JsonParser::jsonToRGBState(String json)
{
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (error)
    {
        Serial.print(F("Failed to parse JSON: "));
        Serial.println(error.c_str());
        return RGBState(0, 0, 0, 0);
    }

    RGBState rgbState(
        doc["red"].as<int>(),
        doc["green"].as<int>(),
        doc["blue"].as<int>(),
        doc["dimmer"].as<int>());
    return rgbState;
}

LightPreset JsonParser::jsonToLightPreset(String json)
{
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (error)
    {
        Serial.print(F("Failed to parse JSON: "));
        Serial.println(error.c_str());
        return LightPreset(0);
    }

    LightPreset lightPreset(
        doc["presetId"].as<int>());
    return lightPreset;
}
