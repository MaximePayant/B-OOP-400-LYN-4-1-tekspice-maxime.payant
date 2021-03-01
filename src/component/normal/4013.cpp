/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4013.cpp
*/

#include "component/normal/4013.hpp"

nts::Component4013::Component4013(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4013")
{
    (void)state;
    m_pinMap[3]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[8]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[1]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4013::simulate(std::size_t tick)
{
    nts::Tristate tmp;
    nts::Tristate tmp1;
    nts::Tristate tmp11;
    nts::Tristate save_output;

    if (m_tick >= tick)
        return;
    m_tick += 1;
    simulatePin(m_pinMap[3], tick);
    simulatePin(m_pinMap[4], tick);
    simulatePin(m_pinMap[5], tick);
    simulatePin(m_pinMap[6], tick);
    tmp = m_pinMap[3].m_state && m_pinMap[5].m_state;
    tmp1 = !(m_pinMap[6].m_state && tmp);
    tmp11 = !(m_pinMap[4].m_state && tmp);
    save_output = m_pinMap[1].m_state;
    m_pinMap[1].m_state = !(tmp1 && m_pinMap[2].m_state);
    m_pinMap[2].m_state = !(tmp11 && save_output);

    simulatePin(m_pinMap[8], tick);
    simulatePin(m_pinMap[9], tick);
    simulatePin(m_pinMap[10], tick);
    simulatePin(m_pinMap[11], tick);
    tmp = m_pinMap[8].m_state && m_pinMap[10].m_state;
    tmp1 = !(m_pinMap[11].m_state && tmp);
    tmp11 = !(m_pinMap[9].m_state && tmp);
    save_output = m_pinMap[12].m_state;
    m_pinMap[12].m_state = !(tmp1 && m_pinMap[13].m_state);
    m_pinMap[13].m_state = !(tmp11 && save_output);
}