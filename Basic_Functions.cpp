#include "Arduino.h"
#include "Basic_Functions.h"
#include <WiFi.h>

#define GMT_OFFSET_HR -6
#define DAYLIGHT_SAVINGS true

Basic_Functions::Basic_Functions(){
    int dayLightOffset_sec = 0;
    SimpleDHT22 dht22(DHT_PIN);
    pinMode(LDR, INPUT);
    //init_time();
}

int Basic_Functions::read_light_level(){
    return analogRead(LDR);
}

void Basic_Functions::init_time(){
    const long gmtOffset_sec = GMT_OFFSET_HR * 3600;
    if(DAYLIGHT_SAVINGS) {dayLightOffset_sec = 3600;}
    else dayLightOffset_sec = 0;
    configTime(gmtOffset_sec, dayLightOffset_sec, "pool.ntp.org");
}

struct tm Basic_Functions::get_time(){
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
    }
    else{
        return timeinfo;
    }
}

void Basic_Functions::print_time(){
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

float Basic_Functions::read_humidity(){
    float temperature = 0;
    float humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Read DHT22 failed, err="); Serial.println(err);delay(2000);
        return 0;
    }
    return (float)humidity;
}

float Basic_Functions::read_temperature(){
    float temperature = 0;
    float humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
        Serial.print("Read DHT22 failed, err="); Serial.println(err);delay(2000);
        return 0;
    }
    return (float)temperature;
}

Basic_Functions::~Basic_Functions(){

}