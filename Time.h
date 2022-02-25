#pragma once
#include <string>
class Time
{
public:
    Time() = default;
    ~Time() = default;
    static std::string getTime();
    static std::string getDay();
    static int64_t now();
private:
};

