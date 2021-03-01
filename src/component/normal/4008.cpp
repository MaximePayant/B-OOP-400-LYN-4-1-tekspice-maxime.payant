/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4008.cpp
*/

#include "component/normal/4008.hpp"

nts::Component4008::Component4008(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4008")
{
    (void)state;
    m_pinMap[1]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[14]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15]  = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13]  = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4008::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}