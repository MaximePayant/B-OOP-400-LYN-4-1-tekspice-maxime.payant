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
#include "../../inc/component/Component.hpp"
#include "console/speach.hpp"

static bool isInput(const std::string& str)
{
    if (str == "input"
    || str == "true"
    || str == "false"
    || str == "clock")
        return (true);
    return (false);
}

void nts::Core::display()
{
    speach::disp("tick: " + std::to_string(tick));
    speach::disp("input(s):");
    for (auto& [name, cpt] : nts::parser)
        if (isInput(cpt.get()->getType()))
            speach::disp("  " + name + ": " + to_string(cpt.get()->compute(1)));
    speach::disp("output(s):");
    for (auto& [name, cpt] : nts::parser)
        if (cpt.get()->getType() == "output")
            speach::disp("  " + name + ": " + to_string(cpt.get()->compute(1)));
}

void nts::Core::setInput(std::string var, std::string value)
{
    auto it = nts::parser.find(var);
    nts::Tristate state = (value == "1" ? nts::TRUE : (value == "0" ? nts::FALSE : nts::UNDEFINED));

    if (it == nts::parser.end())
        throw std::exception();
    else if (it->second.get()->getType() != "input"
    && it->second.get()->getType() != "clock")
        throw std::exception();
    dynamic_cast<nts::Component*>(it->second.get())->m_pinMap[1].m_state = state;
}

void nts::Core::simulate()
{
    tick += 1;
    std::cout << "Starting simulation" << std::endl;
}

void nts::Core::loop()
{
    while (isLoop) {
        simulate();
        display();
        sleep(1);
    }
}

void nts::Core::dump()
{
    for (auto& [_, cpt] : nts::parser)
        cpt.get()->dump();
}