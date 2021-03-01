/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Clock.cpp
*/

#include "component/special/Clock.hpp"

nts::Clock::Clock(const std::string& name, nts::Tristate state) :
    nts::Component(name, "clock")
{
    m_pinMap[1] = {CptInfo::OUTPUT, state, 0, std::nullopt};
}

void nts::Clock::simulate(std::size_t tick)
{
    (void)tick;
    m_pinMap[1].m_state = !m_pinMap[1].m_state;
}