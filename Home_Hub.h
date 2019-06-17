#ifndef Home_Hub_h
#define Home_Hub_h

#include <Arduino.h>
#include "Basic_Functions.h"
#include "Pin_Definitions.h"
#include "Hub_Input.h"
#include "Hub_Output.h"
#include "Hub_IoT.h"

class Home_Hub
{
    public:
        Home_Hub();
        void init(const char* ssid, const char* password);
        float get_temperature();
        float get_humidity();
        void display_message(String message);
        int get_light_level();
        int get_latest_gesture();
        void play_song(const char* name);
        void step_motor(uint8_t motor_id, int steps);
        void set_led_strip(uint8_t r, uint8_t g, uint8_t b);
        int get_button_state(uint8_t pin);
        int get_touch_state(uint8_t pin);
        ~Home_Hub(void);
    private:
        Basic_Functions _basic_func;
        /*Hub_Input _hub_input;
        Hub_Output _hub_output;
        Hub_IoT _hub_iot;*/
        int _wifi_status;
        static const char* _ssid, _password;
};

#endif