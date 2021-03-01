/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Clock.cpp
*/

#include "component/special/Clock.hpp"

nts::Clock::Clock(const std::string& name, nts::Tristate state) :
    nts::Component(name, "clock"),
    m_needChange(false),
    m_waitingState(nts::UNDEFINED)
{
    m_pinMap[1] = {CptInfo::OUTPUT, state, 0, std::nullopt};
}

void nts::Clock::simulate(std::size_t tick)
{
    (void)tick;
    if (m_needChange) {
        m_pinMap[1].m_state = m_waitingState;
        m_needChange = false;
    } else
        m_pinMap[1].m_state = !m_pinMap[1].m_state;
}