#ifndef OBJ_COURIER_CONSTANTS_H
#define OBJ_COURIER_CONSTANTS_H


#include <string>
#include <chrono>

const std::string PROPERTIES_FILE_NAME = "courier.properties";
const std::string DEFAULT_CONFIG = "outfile.name.timestamp=true\nlogging.appender=FILE\nlogging.fileoutpath=\"C:\\Users\\djnic\\git\\obj-courier\"";

const std::string TSTAMP_PROPERTY = "outfile.name.timestamp";
const std::string TSTAMP_PROPERTY_VAL = "true";
const std::string APPENDER_PROPERTY = "logging.appender";
const std::string APPENDER_PROPERTY_VAL = "FILE";
const std::string FILE_OUTPUT_PROPERTY = "logging.fileoutpath";
const std::string FILE_OUTPUT_PROPERTY_VAL = "\"C:\\Users\\djnic\\git\\obj-courier\"";
static int CURRENT_TASK_ID = 0;

enum TASK_STATUS {
    NEW = 0,
    IN_PROGRESS = 1,
    SUSPENDED = 2,
    FINISHED = 3,
    FAILED = 4
};

enum LOG_LEVEL {
    INFO = 0,
    WARNING = 1,
    SEVERE = 2
};

#endif //OBJ_COURIER_CONSTANTS_H
