/*
** EPITECH PROJECT, 2021
** Core.cpp.cc
** File description:
** 
*/

#include <iostream>
#include <csignal>
#include "Core.hpp"

bool Core::isLoop = true;

void signalHandler(int signum)
{
    (void) signum;
    Core::isLoop = false;
}

Core::Core() : inCore(true)
{
    signal(SIGINT, signalHandler);
}

bool Core::isInCore() const
{
    return (inCore);
}

void Core::getValue()
{
    std::string out;

    std::cout << "> ";
    std::cin >> out;
    if (out == "display")
        display();
    if (out == "simulate")
        simulate();
    if (out == "loop")
        loop();
    if (out == "dump")
        dump();
    if (out.find('=') != std::string::npos)
        setInput(out.substr(0, out.find('=')), out.substr(out.find('=') + 1));
    if (out == "exit" || std::cin.eof())
        inCore = false;
}