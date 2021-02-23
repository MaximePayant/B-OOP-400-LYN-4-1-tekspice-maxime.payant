/*
** EPITECH PROJECT, 2021
** instruction.cpp.c
** File description:
**
*/

#include <iostream>
#include <unistd.h>
#include <csignal>
#include "../../inc/core/Core.hpp"
#include "../../inc/factory/Parser.hpp"

void Core::display()
{
    for (auto &component : nts::parser.m_componentMap) {

    }
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