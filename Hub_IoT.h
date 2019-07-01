#ifndef Hub_IoT_H
#define Hub_IoT_H

#include "Home_Hub.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>

class Hub_IoT
{
    public:
        Hub_IoT();
        ~Hub_IoT();
        void publish_webhook(const char* url, String data, const char* event, const char* key);
        void publish_webhook(const char* url, String data);
        
    private:
        HTTPClient client;
};

#endif