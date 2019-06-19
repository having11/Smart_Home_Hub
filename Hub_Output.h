#ifndef Hub_Output_H
#define Hub_Output_H

#include "Pin_Definitions.h"
#include <Arduino.h>
#include "DRV8825.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define MOTOR_STEPS 200
#define MICROSTEPS 32
#define ACTIVE_STATE LOW
#define X 0
#define Y 1

class Hub_Output
{
    public:
        Hub_Output();
        void init_steppers(uint16_t rpm);
        void move_stepper(bool motor_num, int32_t steps);
        long get_stepper_position(uint8_t motor_num);
        void display_message(const char* message, int length);
        void clear_lcd();
        void disable_steppers();
        void set_led_strip(uint8_t r, uint8_t g, uint8_t b);
        ~Hub_Output();
    private:
        uint16_t _stepper_rpm;
        long _stepper_positions[2];
        void init_led();
};

#endif