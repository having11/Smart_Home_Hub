#include <Arduino.h>
#include "Hub_Output.h"

DRV8825 stepper0(MOTOR_STEPS, M1_DIR, M1_STEP, M1_EN);
DRV8825 stepper1(MOTOR_STEPS, M2_DIR, M2_STEP, M2_EN);
LiquidCrystal_I2C lcd(0x3F, 16, 2);

Hub_Output::Hub_Output(){
    init_led();
    set_led_strip(0, 0, 0);
    lcd.begin();
    lcd.backlight();
    lcd.noBlink();
    lcd.noCursor();
}

void Hub_Output::init_steppers(uint16_t rpm){
    uint16_t _stepper_rpm = rpm;
    stepper0.begin(_stepper_rpm);
    stepper0.setEnableActiveState(ACTIVE_STATE);
    stepper0.enable();
    stepper0.setMicrostep(MICROSTEPS);
    stepper1.begin(_stepper_rpm);
    stepper1.setEnableActiveState(ACTIVE_STATE);
    stepper1.enable();
    stepper1.setMicrostep(MICROSTEPS);
    _stepper_positions[X_AXIS] = 0;
    _stepper_positions[Y_AXIS] = 0;
}

void Hub_Output::set_led_strip(uint8_t r, uint8_t g, uint8_t b){
    ledcWrite(1, r);
    ledcWrite(2, g);
    ledcWrite(3, b);
}

void Hub_Output::init_led(){
    pinMode(RGB_R, OUTPUT);
    pinMode(RGB_G, OUTPUT);
    pinMode(RGB_B, OUTPUT);
    ledcAttachPin(RGB_R, 1);
    ledcAttachPin(RGB_G, 2);
    ledcAttachPin(RGB_B, 3);
    ledcSetup(1, 12000, 8);
    ledcSetup(2, 12000, 8);
    ledcSetup(3, 12000, 8);
}

void Hub_Output::disable_steppers(){
    stepper0.enable();
    stepper1.enable();
}

void Hub_Output::clear_lcd(){
    lcd.setCursor(0,0);
    lcd.clear();
}

void Hub_Output::display_message(const char* message, int length){
    clear_lcd();
    lcd.backlight();
    int line=0;
    for(int i=0; i<length;i++){
        if(i%20==0){
            line++;
            lcd.setCursor(0,line);
            Serial.println("new line");
            //lcd.write(message[i]);
        }
        //else if(String(message[i])==String("\0")){}
        else{
            lcd.write(message[i]);
            Serial.write(message[i]);
        } 
        //lcd.write(message[i]);
    }
}

long Hub_Output::get_stepper_position(uint8_t motor_num){
    return _stepper_positions[motor_num];
}

void Hub_Output::move_stepper(bool motor_num, int32_t steps){
    if(!motor_num){
        stepper0.move(MICROSTEPS * steps);
        _stepper_positions[X_AXIS] += steps;
    }
    else{
        stepper1.move(MICROSTEPS * steps);
        _stepper_positions[Y_AXIS] += steps;
    }
}

Hub_Output::~Hub_Output(){

}