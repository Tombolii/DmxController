#include "../include/HttpAdapter.h"

String HttpAdapter::handleHttpRequest(HttpIdentifier httpIdentifier)
{
    if (httpIdentifier.httpMethod == "PUT")
    {
        return handlePutRequest(httpIdentifier);
    }
    else
    {
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
    else
    {
        return NOT_IMPLEMENTED;
    }
};