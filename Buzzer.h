#ifndef Buzzer_h
#define Buzzer_h

#include "Pin_Definitions.h"
#include <Arduino.h>

class Buzzer
{
    public:
        Buzzer();
        void generate_tones(int* melody, int* timing, int length);
        ~Buzzer();
};

#endif