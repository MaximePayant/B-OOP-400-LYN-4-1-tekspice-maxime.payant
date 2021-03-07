/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4040.cpp
*/

#include "component/normal/4040.hpp"

nts::Component4040::Component4040(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4040")
{
    (void)state;
    m_pinMap[1] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[14] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[10] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4040::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
}