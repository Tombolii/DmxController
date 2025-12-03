#ifndef HttpAdapter_h
#define HttpAdapter_h

#include "HttpIdentifier.h"
#include "LightController.h"
#include "HazerController.h"
#include "HttpStatus.h"
#include "JsonParser.h"

#include <Arduino.h>

class HttpAdapter
{
public:
    String handleHttpRequest(HttpIdentifier httpIdentifier);

private:
    const String ROOT_RESPONSE = "ROOT";
    HazerController hazerController = HazerController(1);
    LightController lightController = LightController(3);
    JsonParser jsonParser;

    String handlePutRequest(HttpIdentifier httpIdentifier);
    String handleGetRequest(HttpIdentifier httpIdentifier);
    String handleDeleteRequest(HttpIdentifier httpIdentifier);
};

#endif