#include "Arduino.h"
#include "Home_Hub.h"
#include <WiFi.h>
#include "time.h"

Home_Hub::Home_Hub(){
    Basic_Functions _basic_func();
}

void Home_Hub::init(const char* ssid, const char* password){
    const char* _ssid = ssid;
    const char* _password = password;
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while(WiFi.status() != WL_CONNECTED){
        delay(500);
        Serial.print(".");
    }
    _wifi_status = WL_CONNECTED;
    Serial.println(" CONNECTED");
}

Home_Hub::~Home_Hub(){

}
