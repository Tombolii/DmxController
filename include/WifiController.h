#ifndef WifiController_h
#define WifiController_h

#include "./arduino_secrets.h"
#include "./LightController.h"
#include "./HazerController.h"
#include "../src/HttpAdapter.cpp"
#include "WiFiS3.h"

class WifiController
{
public:
    void initializeWifi(const char *ssid, const char *pass);
    void handleBodyRequests();
    void handleRequests();
    int status = WL_IDLE_STATUS;
    WiFiServer server = WiFiServer(80);

private:
    HttpAdapter httpAdapter;
    HazerController hazerController = HazerController(1);
    LightController lightController = LightController(3);
    IPAddress ipAddress = IPAddress(10, 10, 1, 1);
    void printWiFiStatus();
};

#endif