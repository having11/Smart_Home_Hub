#include "Pin_Definitions.h"
#include "Home_Hub.h"
#include "Hub_Input.h"
#include "Hub_Output.h"
#include "Hub_IoT.h"

Home_Hub hub = Home_Hub();
Hub_IoT iot_connect;

const char* SSID = "wifi ssid here";
const char* PASSWORD = "wifi password here";

unsigned long latest_millis = 0; 
uint16_t print_interval = 1000; 

void setup()
{
	hub.init(SSID, PASSWORD);
	iot_connect.init(&hub);
	latest_millis = millis();
}

void loop()
{
	hub.update();
	if(millis()-latest_millis>=print_interval) {
		hub.print_time();
		latest_millis = millis();
	}
	

}
