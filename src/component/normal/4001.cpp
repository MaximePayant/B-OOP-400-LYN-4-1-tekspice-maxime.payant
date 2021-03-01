/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4001.cpp
*/

#include "component/normal/4001.hpp"

nts::Component4001::Component4001(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4001")
{
    (void)state;
    m_pinMap[3]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[1]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[8]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4001::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
    simulatePin(m_pinMap[1].m_component, m_pinMap[1].m_state, m_pinMap[1].m_linkedPin, tick);
    simulatePin(m_pinMap[2].m_component, m_pinMap[2].m_state, m_pinMap[2].m_linkedPin, tick);
    m_pinMap[3].m_state = !(m_pinMap[1].m_state || m_pinMap[2].m_state);
    simulatePin(m_pinMap[5].m_component, m_pinMap[5].m_state, m_pinMap[5].m_linkedPin, tick);
    simulatePin(m_pinMap[6].m_component, m_pinMap[6].m_state, m_pinMap[6].m_linkedPin, tick);
    m_pinMap[4].m_state = !(m_pinMap[5].m_state || m_pinMap[6].m_state);
    simulatePin(m_pinMap[8].m_component, m_pinMap[8].m_state, m_pinMap[8].m_linkedPin, tick);
    simulatePin(m_pinMap[9].m_component, m_pinMap[9].m_state, m_pinMap[9].m_linkedPin, tick);
    m_pinMap[10].m_state = !(m_pinMap[8].m_state || m_pinMap[9].m_state);
    simulatePin(m_pinMap[12].m_component, m_pinMap[12].m_state, m_pinMap[12].m_linkedPin, tick);
    simulatePin(m_pinMap[13].m_component, m_pinMap[13].m_state, m_pinMap[13].m_linkedPin, tick);
    m_pinMap[11].m_state = !(m_pinMap[12].m_state || m_pinMap[13].m_state);
}