#ifndef Hub_Input_H
#define Hub_Input_H

#include "Pin_Definitions.h"
#include "Arduino.h"
#include <Wire.h>
#include <SparkFun_APDS9960.h>

class Hub_Input
{
    public:
        Hub_Input();
        SparkFun_APDS9960 apds;
        static void IRAM_ATTR isr(void* arg);
        void poll_gesture();
        int get_latest_gesture();
        void create_button(uint8_t pin);
        ~Hub_Input();
    private:
        volatile int _latest_gesture;
        void config_input(uint8_t pin);
        struct Button {
            uint8_t PIN;
            uint32_t numberKeyPresses;
            bool pressed;
        };
        uint8_t _button_number;
        Button button_list[5];
};

#endif