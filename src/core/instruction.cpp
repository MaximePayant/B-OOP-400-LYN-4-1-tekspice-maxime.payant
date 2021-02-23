/*
** EPITECH PROJECT, 2021
** instruction.cpp.c
** File description:
**
*/

#include <iostream>
#include <unistd.h>
#include <csignal>
#include "Core.hpp"

void Core::display()
{
    std::cout << "Display content" << std::endl;
}

void Core::setInput(std::string var, std::string value)
{
    std::cout << "Set variable:[" << var << "] with value:[" << value << "]" << std::endl;
}

void Core::simulate()
{
    std::cout << "Starting simulation" << std::endl;
}

void Core::loop()
{
    while (isLoop) {
        simulate();
        display();
        sleep(1);
    }
}

void Core::dump()
{
    std::cout << "Dump" << std::endl;
}