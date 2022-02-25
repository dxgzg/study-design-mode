#pragma once 
class nocopyable{
public:
    // nocopyable() = delete;
    nocopyable(const nocopyable&) = delete;
    nocopyable& operator=(nocopyable&) = delete;
};