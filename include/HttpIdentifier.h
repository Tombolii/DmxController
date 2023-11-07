#ifndef HttpIdentifier_h
#define HttpIdentifier_h

#include "Arduino.h"

class HttpIdentifier{
    public:
        String httpMethod;
        String path;

        HttpIdentifier(String httpMethod, String path);
};

#endif