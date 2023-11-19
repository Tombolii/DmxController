#ifndef WifiController_h
#define WifiController_h

#include "arduino_secrets.h"
#include "HttpAdapter.h"
#include "HttpIdentifier.h"

#include <Arduino.h>
#include "WiFiS3.h"

class WifiController
{
public:
    void initializeWifi(const char *ssid, const char *pass);
    void handleRequests();
    int status = WL_IDLE_STATUS;
    WiFiServer server = WiFiServer(80);

private:
    HttpAdapter httpAdapter;
    IPAddress ipAddress = IPAddress(10, 10, 1, 1);
    void printWiFiStatus();
    HttpIdentifier extractHttpIdentifier(String line);
    bool isHttpMethodLine(String line);
    bool isLineRootPath(String line);
};

#endif  