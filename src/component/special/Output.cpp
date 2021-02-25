/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Output.cpp
*/

#include "component/special/Output.hpp"

nts::Output::Output(const std::string& name, nts::Tristate state) :
    nts::Component(name, "output")
{
    (void)state;
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, std::nullopt};
}

void nts::Output::simulate(std::size_t tick)
{
    for (auto& [pin, cptInfo] : m_pinMap)
        if (cptInfo.m_type == CptInfo::INPUT
        && cptInfo.m_component.has_value())
            cptInfo.m_component.value().get().simulate(tick);
    if (m_pinMap[1].m_type == CptInfo::INPUT
    && m_pinMap[1].m_component.has_value()) {
        m_pinMap[1].m_component.value().get().simulate(tick);
        m_pinMap[1].m_state = compute(1);
    }
}