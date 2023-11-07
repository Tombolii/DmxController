#include "../include/WifiController.h"
#include "../include/html_content.h"

void WifiController::initializeWifi(const char *ssid, const char *pass)
{
    Serial.println("Access Point Web Server");

    // check for the WiFi module:
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

    // print the network name (SSID);
    Serial.print("Creating access point named: ");
    Serial.println(ssid);

    // Create open network. Change this line if you want to create an WEP network:
    status = WiFi.beginAP(ssid, pass);
    if (status != WL_AP_LISTENING)
    {
        Serial.println("Creating access point failed");
        // don't continue
        while (true)
            ;
    }

    // wait 10 seconds for connection:
    delay(10000);

    // start the web server on port 80
    server.begin();

    // you're connected now, so print out the status
    printWiFiStatus();
}

void WifiController::handleBodyRequests()
{
    // compare the previous status to the current status
    if (status != WiFi.status())
    {
        // it has changed update the variable
        status = WiFi.status();

        if (status == WL_AP_CONNECTED)
        {
            // a device has connected to the AP
            Serial.println("Device connected to AP");
        }
        else
        {
            // a device has disconnected from the AP, and we are back in listening mode
            Serial.println("Device disconnected from AP");
        }
    }

    WiFiClient client = server.available(); // listen for incoming clients

    if (client)
    {                                 // if you get a client,
        Serial.println("new client"); // print a message out the serial port
        String currentLine = "";      // make a String to hold incoming data from the client
        String lastLine = "";
        String body = "";
        int contentLength; 
        while (client.connected())
        {                          // loop while the client's connected
            delayMicroseconds(10); // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
            if (client.available())
            {
                char c = client.read();
                if (c == '\n')
                {
                    
                    

                    if (currentLine.startsWith("Content-Length: "))
                    {
                        Serial.print("Current Line: ");
                        Serial.println(currentLine);
                        contentLength = currentLine.substring(15, currentLine.length()).toInt();
                        Serial.print("Content-Length: ");
                        Serial.println(contentLength);
                    }

                    if (currentLine == "")
                    {
                        for (int i = 0; i < contentLength; i++)
                        {
                            char bc = client.read();
                            body += bc;
                        }

                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();
                        String html = String("test");
                        client.print(html);
                        client.println();
                        break;
                    }
                    lastLine = currentLine;
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

void WifiController::handleRequests()
{
    // Serial.println("handleRequests");
    // compare the previous status to the current status
    if (status != WiFi.status())
    {
        // it has changed update the variable
        status = WiFi.status();

        if (status == WL_AP_CONNECTED)
        {
            // a device has connected to the AP
            Serial.println("Device connected to AP");
        }
        else
        {
            // a device has disconnected from the AP, and we are back in listening mode
            Serial.println("Device disconnected from AP");
        }
    }

    WiFiClient client = server.available(); // listen for incoming clients

    if (client)
    {                                 // if you get a client,
        Serial.println("new client"); // print a message out the serial port
        String currentLine = "";      // make a String to hold incoming data from the client
        String body = "";
        bool readingBody = false;
        while (client.connected())
        { // loop while the client's connected

            delayMicroseconds(10); // This is required for the Arduino Nano RP2040 Connect - otherwise it will loop so fast that SPI will never be served.
            if (client.available())
            {
                // if there's bytes to read from the client,
                char c = client.read(); // read a byte, then
                Serial.write(c);        // print it out to the serial monitor
                if (c == '\n')
                { // if the byte is a newline character
                    if (currentLine.length() == 0)
                    {
                        if (body.length() != 0)
                        {
                            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
                            // and a content-type so the client knows what's coming, then a blank line:
                            client.println("HTTP/1.1 200 OK");
                            client.println("Content-type:text/html");
                            client.println();

                            // the content of the HTTP response follows the header:
                            String html = String(HTML_CONTENT);
                            // client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p>");
                            //  client.print("<p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p>");
                            client.print(html);

                            // The HTTP response ends with another blank line:
                            client.println();
                            // break out of the while loop:
                            break;
                        }
                        else
                        {
                            readingBody = true;
                            currentLine = "";
                        }
                    }
                    // // if the current line is blank, you got two newline characters in a row.
                    // // that's the end of the client HTTP request, so send a response:
                    else
                    { // if you got a newline, then clear currentLine:
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {                     // if you got anything else but a carriage return character,
                    currentLine += c; // add it to the end of the currentLine
                }
                // Check to see if the client request was "GET /H" or "GET /L":
                if (currentLine.endsWith("GET /H"))
                {
                    lightController.lightGreen(); // GET /H turns the LED on
                }
                if (currentLine.endsWith("GET /L"))
                {
                    lightController.lightRGB(255, 100, 0); // GET /L turns the LED off
                }
                if (readingBody)
                {
                    body += c;
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