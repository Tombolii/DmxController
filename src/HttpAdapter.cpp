#include "../include/HttpAdapter.h"

String HttpAdapter::handleHttpRequest(HttpIdentifier httpIdentifier)
{
    Serial.println("Handling request");
    if (httpIdentifier.httpMethod == "PUT")
    {
        return handlePutRequest(httpIdentifier);
    } else if (httpIdentifier.httpMethod == "GET")
    {
        return handleGetRequest(httpIdentifier);
    }
    else
    {
        Serial.print("Method with Path not implemented: ");
        Serial.println(httpIdentifier.httpMethod + " " + httpIdentifier.path);
        return NOT_IMPLEMENTED;
    }
};

String HttpAdapter::handlePutRequest(HttpIdentifier httpIdentifier)
{
    if (httpIdentifier.path == "/hazer/state")
    {
        hazerController.adjustState(jsonParser.jsonToHazerState(httpIdentifier.body));
        return OK;
    }
    else if (httpIdentifier.path =="/light/rgb")
    {
        lightController.lightRGB(jsonParser.jsonToRGBState(httpIdentifier.body));
        return OK;
    }else if (httpIdentifier.path == "/hazer/interval")
    {
        hazerController.startTimer(jsonParser.jsonToHazerInterval(httpIdentifier.body));
        return OK;
    }
    
    else
    {
        Serial.print("Path not implemented: ");
        Serial.println(httpIdentifier.path);
        return NOT_IMPLEMENTED;
    }
};

String HttpAdapter::handleGetRequest(HttpIdentifier httpIdentifier)
{
    if (httpIdentifier.path == "/")
    {
        return ROOT_RESPONSE;
    }
    else
    {
        Serial.print("Path not implemented: ");
        Serial.println(httpIdentifier.path);
        return NOT_IMPLEMENTED;
    }
};