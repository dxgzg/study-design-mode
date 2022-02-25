#pragma once
#include <string>

#include "LoggerConfig.h"
#include "nocopyable.h"
#include "LoggerLevel.h"
#include "Time.h"

class Logger{
public:
    // Logger(const Logger&) = delete;

    template<typename ...Args>
    void LOG_ERROR(std::string format,Args... args){
        process(&LogLevelSignletonFactory::getLoError(),format,std::forward<Args>(args)...);
    }

    template<typename ...Args>
    void LOG_FATAL(std::string format,Args... args){
        process(&LogLevelSignletonFactory::getLogFatal(),format,std::forward<Args>(args)...);
    }
    

    template<typename ...Args>
    void LOG_INFO(std::string format,Args... args){
        process(&LogLevelSignletonFactory::getLogInfo(),format,std::forward<Args>(args)...);
    }

protected:
    virtual void print(std::string& ) = 0;

    template<typename T,typename ... Args>
    std::string mySnprint(std::string& format,T&& t,Args&& ...args){
        char buff[mySnprintBuffSize];
        snprintf(buff,sizeof(buff),format.c_str(),t,args...);
        format = std::move(buff);
        mySnprint(format,std::forward<Args>(args)...);

        return format;
    }
    std::string mySnprint(std::string& s){return s;} // 出口函数

    template<typename ...Args>
    void process(LogLevel* llevel,std::string& format,Args... args){
        std::string s(llevel->getString());
        s += Time::getTime() + " ";
        s += mySnprint(format,std::forward<Args>(args)...);

        this->print(s);// 多态，运行时候的
    }
};

class ControlLogger: public Logger{
public:
    ControlLogger() = default;
    virtual void print(std::string& )override;
};

// class FileLogger : public Logger{
// public:

// };

