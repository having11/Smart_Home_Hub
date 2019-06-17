#ifndef Log_h
#define Log_h

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "Basic_Functions.h"
#include "Pin_Definitions.h"
#include "time.h"

class Logger
{
    public:
        Logger();
        void begin_log(const char* filename, const char* header);
        void log_info(const char* filename, struct tm* timeinfo, const char* data);
        ~Logger();
    private:
        File log_file;
};

#endif