/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** True.cpp
*/

#include "component/special/True.hpp"

nts::True::True(const std::string& name, nts::Tristate state) :
    nts::Component(name, "true"),
    m_needChange(true),
    m_waitingState(nts::TRUE)
{
    (void)state;
    m_pinMap[1] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::True::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
    if (m_needChange) {
        m_pinMap[1].m_state = m_waitingState;
        m_needChange = false;
    }
}