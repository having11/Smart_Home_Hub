#include <Arduino.h>
#include "Hub_Input.h"

Hub_Input::Hub_Input(){
    _button_number = 0;
    SparkFun_APDS9960 apds = SparkFun_APDS9960();
    if ( apds.init() ) {
        Serial.println(F("APDS-9960 initialization complete"));
    } else {
        Serial.println(F("Something went wrong during APDS-9960 init!"));
    }
    if ( apds.enableGestureSensor(false) ) {
        Serial.println(F("Gesture sensor is now running"));
    } else {
        Serial.println(F("Something went wrong during gesture sensor init!"));
    }
}

void Hub_Input::config_input(uint8_t pin){
    pinMode(pin, INPUT_PULLUP);
}

void Hub_Input::create_button(uint8_t pin){
    if(_button_number < 5){
        config_input(pin);
        _button_number++;
        Button new_button = {pin, 0, false};
        button_list[_button_number-1] = new_button;
        attachInterruptArg(new_button.PIN,isr,&new_button, FALLING); 
    }
    else Serial.println(F("Too many buttons have already been created"));
}

int Hub_Input::get_latest_gesture(){
    return _latest_gesture;
}

void Hub_Input::poll_gesture(){
    if(apds.isGestureAvailable()){
        _latest_gesture = apds.readGesture();
    }
}

void IRAM_ATTR Hub_Input::isr(void* arg){
    Button* s = static_cast<Button*>(arg);
    s->numberKeyPresses++;
    s->pressed = true;
}

Hub_Input::~Hub_Input(){

}