#ifndef Basic_Functions_h
#define Basic_Functions_h

#include <Arduino.h>
#include "Pin_Definitions.h"
#include <SimpleDHT.h>
#include <WiFi.h>
#include "time.h"

class Basic_Functions
{
    public:
        Basic_Functions();
        void init_time();
        struct tm get_time();
        SimpleDHT22 dht22;
        float read_humidity();
        float read_temperature();
        int read_light_level();
        void print_time();
        ~Basic_Functions();
    private:
        struct tm timeinfo;
        static const char* ntpServer;
        static const long gmtOffset_sec;
        int dayLightOffset_sec; 
};

#endif