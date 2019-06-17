#include <Arduino.h>
#include "Log.h"

Logger::Logger(){
    if(!SD.begin(SD_CS)){
        Serial.println("SD init failed");
    }
}

void Logger::begin_log(const char* filename, const char* header){
    log_file = SD.open(filename, FILE_WRITE);
    log_file.println(header);
    log_file.close();
}

void Logger::log_info(const char* filename, struct tm* timeinfo, const char* data){
    log_file = SD.open(filename, FILE_WRITE);
    log_file.print(timeinfo->tm_year); log_file.print(" ");
    log_file.print(timeinfo->tm_mon); log_file.print(" ");
    log_file.print(timeinfo->tm_mday); log_file.print(" ");
    log_file.print(timeinfo->tm_hour); log_file.print(":");
    log_file.print(timeinfo->tm_min); log_file.print(":");
    log_file.print(timeinfo->tm_sec); log_file.print(" , ");
    log_file.println(data);
    log_file.close();
}

Logger::~Logger(){

}