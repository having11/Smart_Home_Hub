#ifndef Hub_IoT_H
#define Hub_IoT_H

#include "Home_Hub.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

class Hub_IoT
{
    public:
        Hub_IoT();
        void init(Home_Hub *hub);

        ~Hub_IoT();

    private:
        Home_Hub *_hub;
        WebServer server;
};

#endif