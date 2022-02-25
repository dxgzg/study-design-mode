#include "Time.h"

#include <sys/time.h>
using namespace std;

string Time::getTime(){
    char buff[128] = {0};
    tm tm_time;
    int64_t seconds = now();
    localtime_r(&seconds, &tm_time);
    snprintf(buff, sizeof(buff), "%4d-%02d-%02d %02d:%02d:%02d",
    tm_time.tm_year + 1900,
    tm_time.tm_mon + 1,
    tm_time.tm_mday,
    tm_time.tm_hour,
    tm_time.tm_min,
    tm_time.tm_sec
    );
    return buff;
}
string Time::getDay(){
    char buff[128] = {0};
    tm tm_time;
    int64_t seconds = now();
    localtime_r(&seconds, &tm_time);
    snprintf(buff, sizeof(buff), "%4d-%02d-%02d",
    tm_time.tm_year + 1900,
    tm_time.tm_mon + 1,
    tm_time.tm_mday
    );
    return buff;
}
int64_t Time::now(){
    timeval tm;
    gettimeofday(&tm,NULL);
    struct tm tm_time;
    auto seconds = tm.tv_sec; 
    return seconds;
}