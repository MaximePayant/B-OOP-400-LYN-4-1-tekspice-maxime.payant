/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Logger.cpp
*/

#include "component/special/Logger.hpp"

nts::Logger::Logger(const std::string& name, nts::Tristate state) :
    nts::Component(name, "logger")
{
    (void)state;
}

void nts::Logger::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}