#include "../include/HttpIdentifier.h"

HttpIdentifier::HttpIdentifier(String httpMethod, String path)
{
    this->httpMethod = httpMethod;
    this->path = path;
}

