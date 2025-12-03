#include <Arduino.h>

// #include "./include/WifiController.h"
// #include "./include/arduino_secrets.h"
#include "WifiController.h"
#include "arduino_secrets.h"

#include "WifiController.h"

WifiController wifiController;  

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;


void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
  wifiController.initializeWifi(ssid, pass);
}

void loop()
{
  wifiController.handleRequests();
  HazerController::checkTimer();
}