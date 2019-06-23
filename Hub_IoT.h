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
        void init(Home_Hub *hub);
        void refresh();
        ~Hub_IoT();

    private:
        Home_Hub *_hub;
        WebServer server;
        HTTPClient client;

        void handle_basic_info();
        void handle_led();
        void handle_lcd();
        void handle_stepper();
        void handle_temperature();
        void handle_humidity();
        void handle_light_level();
        void handle_gesture();
        void handle_touch();
        void handle_button();
        void handle_log();

        void publish_webhook(const char* url, String data, const char* event);
        void publish_webhook(const char* url, String data);
};

#endif