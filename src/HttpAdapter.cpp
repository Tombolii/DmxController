#include "../include/HttpAdapter.h"

void HttpAdapter::handleHttpRequest(HttpIdentifier httpPathMethod)
{
    Serial.println("Handling HTTP request...");
    Serial.print("Method: ");
    Serial.println(httpPathMethod.httpMethod);
    Serial.print("Path: ");
    Serial.println(httpPathMethod.path);
};