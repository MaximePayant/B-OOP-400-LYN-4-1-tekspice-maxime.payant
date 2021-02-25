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
    m_pinMap[3] = {CptInfo::OUTPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[11] = {CptInfo::OUTPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[2] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[5] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[6] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[8] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[9] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[12] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
    m_pinMap[13] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
}

void nts::Component4001::simulate(std::size_t tick)
{
    for (auto& [pin, cptInfo] : m_pinMap)
        if (cptInfo.m_type == CptInfo::INPUT
        && cptInfo.m_component.has_value())
            cptInfo.m_component.value().get().simulate(tick);
}