#include "Pin_Definitions.h"
#include "Home_Hub.h"
#include "Hub_Input.h"
#include "Hub_Output.h"
#include "Hub_IoT.h"

Home_Hub hub = Home_Hub();
Hub_IoT iot_connect;

const char* SSID = "ssid";
const char* PASSWORD = "password";

unsigned long latest_millis = 0; 
uint16_t print_interval = 1000; 
byte wheelPos = 0;

void setup()
{
	hub.init(SSID, PASSWORD);
	latest_millis = millis();
}

void loop()
{
	if(wheelPos > 255){
		wheelPos = 0;
	}
	hub.update();
	if(millis()-latest_millis>=print_interval) {
		hub.print_time();
		latest_millis = millis();
	}
	Wheel(wheelPos);
	wheelPos++;
}

void Wheel(byte wheelPos){
	if(wheelPos < 85){
		hub.set_led_strip(wheelPos * 3, 255 - wheelPos * 3, 0);
	}
	else if(wheelPos < 170){
		wheelPos -= 85;
		hub.set_led_strip(255 - wheelPos * 3, 0, wheelPos * 3);
	}
	else{
		wheelPos -= 170;
		hub.set_led_strip(0, wheelPos * 3, 255 - wheelPos * 3);
	}
	delay(20);
}