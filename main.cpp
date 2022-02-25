#include <iostream>

#include "Logger.h"
using namespace std;
// 为什么模板必须写在H文件中
int main(){
    Logger* logger = new ControlLogger();
    logger->LOG_INFO("hello");
    logger->LOG_INFO("hello %s","world");
    logger->LOG_INFO("hello %d",22);
    logger->LOG_ERROR("it is a error");
    logger->LOG_FATAL("it is a fatal");

    delete logger;
    return 0;
}