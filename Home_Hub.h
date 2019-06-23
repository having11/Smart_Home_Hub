#ifndef Home_Hub_h
#define Home_Hub_h

#include <Arduino.h>
#include "Basic_Functions.h"
#include "Pin_Definitions.h"
#include "Hub_Input.h"
#include "Hub_Output.h"
#include "Log.h"
#include "Buzzer.h"

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
        void print_time();
        void step_motor(uint8_t motor_id, int32_t steps);
        void set_led_strip(uint8_t r, uint8_t g, uint8_t b);
        bool get_button_state(uint8_t pin);
        int get_touch_state(uint8_t pin);
        void create_button(uint8_t pin);
        struct tm get_current_time();
        void log_to_file(const char* data, const char* filename);
        void create_log(const char* filename, const char* header);
        void play_sounds(int* melody, int* timing, int length);
        void update();

        Basic_Functions _basic_func;
        Hub_Input _hub_input;
        Hub_Output _hub_output;
        Buzzer _buzzer;
        Logger _logger;

        struct tm time_data;

        ~Home_Hub(void);
    private:
        
        uint16_t rpm;
        int _wifi_status;
        static const char* _ssid, _password;
};

#endif