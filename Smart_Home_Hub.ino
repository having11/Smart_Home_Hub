#include "Pin_Definitions.h"
#include "Home_Hub.h"
#include "Hub_Input.h"
#include "Hub_Output.h"

Home_Hub hub = Home_Hub();

void setup()
{
	hub.init("Gato", "wedding1999");
}

void loop()
{
	hub._hub_input.poll_gesture();
}
