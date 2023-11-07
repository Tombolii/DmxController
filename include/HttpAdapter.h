#ifndef HttpAdapter_h
#define HttpAdapter_h

#include "HttpIdentifier.h"

#include <Arduino.h>

class HttpAdapter {
    public:
        void handleHttpRequest(HttpIdentifier httpPathMethod);
};

#endif