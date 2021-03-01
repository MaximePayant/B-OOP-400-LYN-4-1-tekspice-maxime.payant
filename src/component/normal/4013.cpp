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
    if (m_tick >= tick)
        return;
    m_tick += 1;
}