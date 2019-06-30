#include "Hub_IoT.h"

Hub_IoT::Hub_IoT(){
    WebServer server(80);
}

void Hub_IoT::init(Home_Hub *hub){
    _hub = hub;
    if(MDNS.begin("esp32")){
        Serial.println("MDNS responder started");
    }
    server.on("/", handle_basic_info);
    server.on("/output/led", handle_led);
    server.on("/output/lcd", handle_lcd);
    server.on("/output/stepper/{}", handle_stepper);
    server.on("/basic/temperature", handle_temperature);
    server.on("/basic/humidity", handle_humidity);
    server.on("/basic/light_level", handle_light_level);
    server.on("/input/gesture", handle_gesture);
    server.on("/input/touch/pin/{}", handle_touch);
    server.on("/input/button/pin/{}", handle_button);
    server.on("/log", handle_log);

    server.begin();
}

void Hub_IoT::publish_webhook(const char* url, String data, const char* event){
    client.begin(url);
    client.addHeader("Content-Type", "application/json");
    client.addHeader("Event", event);
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

void Hub_IoT::refresh(){
    server.handleClient();
}(

void Hub_IoT::handle_stepper(){

}

void Hub_IoT::handle_temperature(){

}

void Hub_IoT::handle_humidity(){

}

void Hub_IoT::handle_light_level(){

}

void Hub_IoT::handle_gesture(){

}

void Hub_IoT::handle_touch(){

}

void Hub_IoT::handle_button(){

}

void Hub_IoT::handle_basic_info(){
    server.send(200, "text/plain", "Server is live at " + String(WiFi.localIP()));
}

void Hub_IoT::handle_led(){
    uint8_t r = server->arg("R").toInt();
    uint8_t g = server->arg("G").toInt();
    uint8_t b = server->arg("B").toInt();
    _hub->set_led_strip(r, g, b);
    server.send(200, "text/plain", "Set LED strip");
}

void Hub_IoT::handle_lcd(){
    String message = server->arg("message");
    _hub->display_message(message);
    server.send(200, )
}

Hub_IoT::~Hub_IoT(){

}
