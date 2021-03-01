/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4069.cpp
*/

#include "component/normal/4069.hpp"

nts::Component4069::Component4069(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4069")
{
    (void)state;
    m_pinMap[2] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[8] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

}

void nts::Component4069::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    simulatePin(m_pinMap[1], tick);
    m_pinMap[2].m_state = !m_pinMap[1].m_state;
    simulatePin(m_pinMap[3], tick);
    m_pinMap[4].m_state = !m_pinMap[1].m_state;
    simulatePin(m_pinMap[5], tick);
    m_pinMap[6].m_state = !m_pinMap[1].m_state;
    simulatePin(m_pinMap[9], tick);
    m_pinMap[8].m_state = !m_pinMap[1].m_state;
    simulatePin(m_pinMap[11], tick);
    m_pinMap[10].m_state = !m_pinMap[1].m_state;
    simulatePin(m_pinMap[13], tick);
    m_pinMap[12].m_state = !m_pinMap[1].m_state;
}