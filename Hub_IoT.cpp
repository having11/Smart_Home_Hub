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
    server.on("/output/stepper", handle_stepper);
    server.on("/basic/temperature", handle_temperature);
    server.on("/basic/humidity", handle_humidity);
    server.on("/basic/light_level", handle_light_level);
    server.on("/input/gesture", handle_gesture);
    server.on("/input/touch", handle_touch);
    server.on("/input/button/pin/{}", handle_button);
}

Hub_IoT::~Hub_IoT(){

}
