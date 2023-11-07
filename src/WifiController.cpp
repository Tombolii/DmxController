#include "../include/WifiController.h"
#include "../include/html_content.h"

void WifiController::initializeWifi(const char *ssid, const char *pass)
{
    Serial.println("Access Point Web Server");

    if (WiFi.status() == WL_NO_MODULE)
    {
        Serial.println("Communication with WiFi module failed!");
        while (true)
            ;
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION)
    {
        Serial.println("Please upgrade the firmware");
    }

    WiFi.config(ipAddress);

    Serial.print("Creating access point named: ");
    Serial.println(ssid);

    status = WiFi.beginAP(ssid, pass);
    if (status != WL_AP_LISTENING)
    {
        Serial.println("Creating access point failed");
        while (true)
            ;
    }

    delay(10000);

    server.begin();

    printWiFiStatus();
}

void WifiController::handleRequests()
{
    if (status != WiFi.status())
    {
        status = WiFi.status();

        if (status == WL_AP_CONNECTED)
        {
            Serial.println("Device connected to AP");
        }
        else
        {
            Serial.println("Device disconnected from AP");
        }
    }

    WiFiClient client = server.available();

    if (client)
    {
        Serial.println("new client");
        String httpIdentifierLine;
        String currentLine = "";
        String body = "";
        int contentLength;
        while (client.connected())
        {
            delayMicroseconds(10); // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
            if (client.available())
            {
                char c = client.read();
                if (c == '\n')
                {
                    if (isLineRootPath(currentLine))
                    {
                        sendHTMLResponse(client);
                        break;
                    }

                    if (isHttpMethodLine(currentLine))
                    {
                        httpIdentifierLine = currentLine;
                    }

                    if (currentLine.startsWith("Content-Length: "))
                    {
                        contentLength = currentLine.substring(15, currentLine.length()).toInt();
                    }

                    if (currentLine == "")
                    {
                        for (int i = 0; i < contentLength; i++)
                        {
                            char bc = client.read();
                            body += bc;
                        }

                        httpAdapter.handleHttpRequest(extractHttpIdentifier(httpIdentifierLine));
                        client.println("HTTP/1.1 201 CREATED");
                        break;
                    }
                    currentLine = "";
                }
                else if (c != '\r')
                {
                    currentLine += c;
                }
            }
        }
        // close the connection:
        client.stop();
        Serial.println("client disconnected");
        Serial.print("request: ");
        Serial.println(body);
    }
}

void WifiController::printWiFiStatus()
{
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print where to go in a browser:
    Serial.print("To see this page in action, open a browser to http://");
    Serial.println(ip);
}

HttpIdentifier WifiController::extractHttpIdentifier(String line)
{   
    int firstSpaceIndex = line.indexOf(" ");
    String httpMethod = line.substring(0, firstSpaceIndex);
    
    String requestPathLine = line.substring(firstSpaceIndex + 1);
    int secondSpaceIndex = requestPathLine.indexOf(" ");
    String requestPath = requestPathLine.substring(0, secondSpaceIndex);

    return HttpIdentifier(httpMethod, requestPath);
}

bool WifiController::isHttpMethodLine(String line)
{
    return line.startsWith("POST") || line.startsWith("GET") || line.startsWith("PUT") || line.startsWith("DELETE");
}

bool WifiController::isLineRootPath(String line)
{
    return line.startsWith("GET / ");
}

void WifiController::sendHTMLResponse(WiFiClient client)
{
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    String html = String(HTML_CONTENT);
    client.print(html);
    client.println();
}