#include "Hub_IoT.h"

Hub_IoT::Hub_IoT(){
}

void Hub_IoT::publish_webhook(const char* url, String data, const char* event, const char* key){
    String url_str = url;
    url_str.concat(event);
    url_str.concat("/with/key/");
    url_str.concat(key);
    client.begin(url_str);
    client.addHeader("Content-Type", "application/json");
    int httpRes = client.POST(data);
    if(httpRes){
        String response = client.getString();
        Serial.println(httpRes);
        Serial.println(response);
    }
    else{
        Serial.print("Error: ");
        Serial.println(httpRes);
    }
    client.end();
}

void Hub_IoT::publish_webhook(const char* url, String data){
    client.begin(url);
    client.addHeader("Content-Type", "application/json");
    int httpRes = client.POST(data);
    if(httpRes){
        String response = client.getString();
        Serial.println(httpRes);
        Serial.println(response);
    }
    else{
        Serial.print("Error: ");
        Serial.println(httpRes);
    }
    client.end();
}

Hub_IoT::~Hub_IoT(){

}
