/*
** EPITECH PROJECT, 2021
** Core.hpp.h
** File description:
**
*/

#ifndef B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE
#define B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE

#include <string>

class Core
{
private:
    bool inCore;

public:
    static bool isLoop;

    Core();
    ~Core() = default;
    bool isInCore() const;
    void getValue();
    void display();
    void setInput(std::string var, std::string value);
    void simulate();
    void loop();
    void dump();
};

void signalHandler(int signum);

#endif //B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE
