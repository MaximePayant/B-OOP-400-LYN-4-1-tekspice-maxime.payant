/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4030.cpp
*/

#include "component/normal/4030.hpp"

nts::Component4030::Component4030(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4030")
{
    (void)state;
    m_pinMap[3] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[8] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

}

void nts::Component4030::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
    simulatePin(m_pinMap[1], tick);
    simulatePin(m_pinMap[2], tick);
    m_pinMap[3].m_state = m_pinMap[1].m_state ^ m_pinMap[2].m_state;
    simulatePin(m_pinMap[5], tick);
    simulatePin(m_pinMap[6], tick);
    m_pinMap[4].m_state = m_pinMap[5].m_state ^ m_pinMap[6].m_state;
    simulatePin(m_pinMap[13], tick);
    simulatePin(m_pinMap[14], tick);
    m_pinMap[11].m_state = m_pinMap[14].m_state ^ m_pinMap[13].m_state;
    simulatePin(m_pinMap[8], tick);
    simulatePin(m_pinMap[9], tick);
    m_pinMap[12].m_state = m_pinMap[8].m_state ^ m_pinMap[9].m_state;
}