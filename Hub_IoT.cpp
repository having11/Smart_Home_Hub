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
    server.on("/log", handle_log);

    server.begin();
}

void Hub_IoT::refresh(){
    server.handleClient();
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

Hub_IoT::~Hub_IoT(){

}
