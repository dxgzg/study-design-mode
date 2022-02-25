#pragma once
#include <string>

#include "nocopyable.h"

class LogLevel{
public: 
    virtual std::string getString() = 0;
};

class Info : public LogLevel{
public:
    virtual std::string getString()override{
        return "[INFO] ";
    }
};

class Error : public LogLevel{
public:
    virtual std::string getString()override{
        return "[ERROR] ";
    }
};

class Fatal : public LogLevel{
public:
    virtual std::string getString()override{
        return "[FATAL] ";
    }
};

class LogLevelSignletonFactory: public nocopyable{
public:
    static Info& getLogInfo(){
        static Info i;
        return i;
    }
    static Error& getLoError(){
        static Error e;
        return e;
    }
    static Fatal& getLogFatal(){
        static Fatal f;
        return f;
    }
    virtual LogLevel& createSignleLogLevel() = 0;
};

// class LogLevelInfoFactory : public LogLevelSignletonFactory{
// public:
//     LogLevel& createSignleLogLevel()override{
//         static Info i;
//         return i;
//     }
// };

// class LogLevelErrorFactory : public LogLevelSignletonFactory{
// public:
//     LogLevel& createSignleLogLevel()override{
//         static Error e;
//         return e;
//     }
// };

// class LogLevelFatalFactory : public LogLevelSignletonFactory{
// public:
//     LogLevel& createSignleLogLevel()override{
//         static Fatal f;
//         return f;
//     }
// };