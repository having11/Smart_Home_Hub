# Smart Home Hub Project

## Link to the project on [Hackster.io](https://www.hackster.io/gatoninja236/esp32-smart-home-hub-6e8049)

There is a wrapper class for the home hub board called `Home_Hub`, which contains all necessary functions in a clean format.

![Device Front](images/front.JPG)

## Commands

**Here is a list of callable functions from `Home_Hub`:**

```cpp
void init(const char* ssid, const char* password)
float get_temperature()
float get_humidity()
void display_message(String message)
int get_light_level()
int get_latest_gesture()
void print_time()
void step_motor(uint8_t motor_id, int32_t steps)
void set_led_strip(uint8_t r, uint8_t g, uint8_t b)
bool get_button_state(uint8_t pin)
int get_touch_state(uint8_t pin)
void create_button(uint8_t pin)
struct tm get_current_time()
void log_to_file(const char* data, const char* filename)
void create_log(const char* filename, const char* header)
void play_sounds(int* melody, int* timing, int length)
void update()
```

## Descriptions

`init()` gets called in the `setup` function in the sketch to connect to wifi and prints basic connection information

`get_temperature()` returns the temperature in the form of a floating point number

`get_humidity()` returns the humidity in the form of a floating point number

`display_message(String message)` displays a string on a connected I2C LCD, such as this one: 
![LCD](images/lcd.JPG)

`update()` should be called in `loop()` to poll devices such as the APDS9960

`get_light_level()` returns an int of the value read by the photoresistor

`get_latest_gesture()` returns the latest gesture read by the APDS9960

`print_time()` simply prints the current time via serial

`step_motor(uint8_t motor_id, int32_t steps)` steps one of the two stepper motors via the dual DRV8825 drivers. Motor ID can be either 0 or 1.
![Drivers](images/stepper_drivers.JPG)

`set_led_strip(uint8_t r, uint8_t g, uint8_t b)` sets the analog LED strip to that color, given in RGB format.
![LED Strip](images/led_strip.JPG)
![MOSFETS](images/mosfets.JPG)

`create_button(uint8_t pin)` **must** be called only **_once_** to setup a button for the given pin

`get_button_state(uint8_t pin)` returns a boolean, 1 if pressed, 0 if not pressed

`get_touch_state(uint8_t pin)` returns an int of the value of the capacitive touch pin
![IO Header](images/io_top.JPG)

`get_current_time()` returns a `tm` struct that contains the date and time

`create_log(const char* filename, const char* header)` **must** be called before logging. It sets up a new file in a CSV format, where header is the string for the columns.

`log_to_file(const char* data, const char* filename)` writes data to a row in the file

`play_sounds(int* melody, int* timing, int length)` plays a song with the onboard buzzer using the same format as the Arduino tone example. Just put in the notes, delays, and finally the length of the ditty.