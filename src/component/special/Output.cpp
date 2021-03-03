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
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Output::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
    if (m_pinMap[1].m_component.has_value()) {
        m_pinMap[1].m_component.value().get().simulate(tick);
        m_pinMap[1].m_state = m_pinMap[1].m_component.value().get().compute(m_pinMap[1].m_linkedPin);
    }
}