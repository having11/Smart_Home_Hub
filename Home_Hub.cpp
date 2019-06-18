#include "Arduino.h"
#include "Home_Hub.h"
#include <WiFi.h>
#include "time.h"

#define RPM 90
#define GMT_OFFSET_HR -6
#define DAYLIGHT_SAVINGS true

Home_Hub::Home_Hub(){
    rpm = RPM;
    Basic_Functions _basic_func();
    Hub_Input _hub_input();
    Hub_Output _hub_output();
    Buzzer _buzzer();
    Logger _logger();
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
    _hub_output.init_steppers(rpm);
}

void Home_Hub::step_motor(uint8_t motor_id, int32_t steps){
    _hub_output.move_stepper(motor_id, steps);
}

void Home_Hub::set_led_strip(uint8_t r, uint8_t g, uint8_t b){
    _hub_output.set_led_strip(r, g, b);
}

void Home_Hub::create_button(uint8_t pin){
    _hub_input.create_button(pin);
}

bool Home_Hub::get_button_state(uint8_t pin){
    return _hub_input.get_button_is_pressed(pin);
}

int Home_Hub::get_touch_state(uint8_t pin){
    return _hub_input.get_touched_value(pin);
}

float Home_Hub::get_temperature(){
    return _basic_func.read_temperature();
}

float Home_Hub::get_humidity(){
    return _basic_func.read_humidity();
}

void Home_Hub::display_message(String message){
    _hub_output.display_message(message.c_str());
}

void Home_Hub::print_time(){
    _basic_func.print_time();
}

int Home_Hub::get_light_level(){
    return _basic_func.read_light_level();
}

int Home_Hub::get_latest_gesture(){
    return _hub_input.get_latest_gesture();
}

Home_Hub::~Home_Hub(){

}
