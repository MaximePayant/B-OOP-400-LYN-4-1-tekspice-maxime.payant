/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4094.cpp
*/

#include "component/normal/4094.hpp"

nts::Component4094::Component4094(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4094")
{
    (void)state;
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[14] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4094::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
}