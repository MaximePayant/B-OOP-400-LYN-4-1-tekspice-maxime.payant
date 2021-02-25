/*
** EPITECH PROJECT, 2021
** Core.cpp.cc
** File description:
**
*/

#include <iostream>
#include <csignal>
#include "../../inc/core/Core.hpp"

bool nts::Core::isLoop = true;
bool nts::Core::inCore = true;
std::size_t nts::Core::tick = 0;

static void signalHandler(int signum)
{
    (void) signum;
    nts::Core::isLoop = false;
}

nts::Core::Core()
{
    signal(SIGINT, signalHandler);
}

void nts::Core::getValue()
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