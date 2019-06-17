#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(){
    pinMode(BUZZER, OUTPUT);
    ledcSetup(4, 2000, 16);
    ledcAttachPin(BUZZER, 4);
}

void Buzzer::generate_tones(int* melody, int* timing, int length){
    for(int i=0; i<length; i++){
        int noteDuration = 1000 / timing[i];
        ledcWriteTone(4, melody[i]);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        ledcWrite(4, 0);
    }
}

Buzzer::~Buzzer(){

}