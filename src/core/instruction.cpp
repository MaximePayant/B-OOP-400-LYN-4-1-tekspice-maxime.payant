/*
** EPITECH PROJECT, 2021
** instruction.cpp.c
** File description:
**
*/

#include <iostream>
#include <unistd.h>
#include <csignal>
#include <error/Error.hpp>
#include "../../inc/core/Core.hpp"
#include "../../inc/factory/Parser.hpp"
#include "../../inc/component/Component.hpp"
#include "../../inc/component/special/Clock.hpp"
#include "../../inc/component/special/Input.hpp"
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
    nts::Tristate state;

    if (value == "0" || value == "1" || value == "U")
        state = (value == "1" ? nts::TRUE : (value == "0" ? nts::FALSE : nts::UNDEFINED));
    else
        throw nts::Error("ERROR: Wrong value!");
    if (it == nts::parser.end())
        throw nts::Error("ERROR: Component not found!");
    else if (it->second.get()->getType() == "input") {
        dynamic_cast<nts::Input*>(it->second.get())->m_needChange = true;
        dynamic_cast<nts::Input*>(it->second.get())->m_waitingState = state;
    }
    else if (it->second.get()->getType() == "clock") {
        dynamic_cast<nts::Clock*>(it->second.get())->m_needChange = true;
        dynamic_cast<nts::Clock*>(it->second.get())->m_waitingState = state;
    }
    else
        throw nts::Error("ERROR: Component <" + var + "> is not an input or a clock!");
}

void nts::Core::simulate()
{
    tick += 1;
    for (auto& [_, cpt] : nts::parser)
        if (cpt.get()->getType() == "output")
            cpt.get()->simulate(tick);
    for (auto& [_, cpt] : nts::parser)
        cpt.get()->simulate(tick);
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