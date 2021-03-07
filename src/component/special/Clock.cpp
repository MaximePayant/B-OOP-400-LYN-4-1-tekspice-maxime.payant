/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Clock.cpp
*/

#include "component/special/Clock.hpp"

nts::Clock::Clock(const std::string& name, nts::Tristate state) :
    nts::Component(name, "clock"),
    m_needChange(true),
    m_waitingState(state)
{
    m_pinMap[1] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Clock::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
    if (m_needChange) {
        m_pinMap[1].m_state = m_waitingState;
        m_needChange = false;
    } else
        m_pinMap[1].m_state = !m_pinMap[1].m_state;
}