#ifndef HttpIdentifier_h
#define HttpIdentifier_h

#include "Arduino.h"

class HttpIdentifier{
    public:
        String httpMethod;
        String path;
        String body;

        HttpIdentifier(String httpMethod, String path);
};

#endif