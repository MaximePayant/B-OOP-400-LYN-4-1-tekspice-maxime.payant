/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.cpp
*/

#include "console/speach.hpp"
#include "factory/Parser.hpp"
#include "component/Component.hpp"

nts::Component::Component(const std::string& name, const std::string& type, nts::Tristate state) :
    m_name(name),
    m_type(type),
    m_state(state)
{}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    auto it = m_inputPinMap.find(pin);

    if (it == m_inputPinMap.end())
        it = m_outputPinMap.find(pin);
    if (it == m_outputPinMap.end())
        throw std::exception();
    if (!it->second.has_value())
        throw std::exception();
    return (reinterpret_cast<nts::Component&>(it->second.value()).m_state);
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Component& otherCpt = reinterpret_cast<nts::Component&>(other);

    if (m_inputPinMap.count(pin)) {
        if (otherCpt.m_inputPinMap.count(otherPin))
            throw std::exception();
        else if (!otherCpt.m_outputPinMap.count(otherPin))
            throw std::exception();
        else {
            *m_inputPinMap[pin] = otherCpt;
            *otherCpt.m_outputPinMap[otherPin] = *this;
        }
    }
    else if (m_outputPinMap.count(pin)) {
        if (otherCpt.m_outputPinMap.count(otherPin))
            throw std::exception();
        else if (!otherCpt.m_inputPinMap.count(otherPin))
            throw std::exception();
        else {
            *m_outputPinMap[pin] = otherCpt;
            *otherCpt.m_inputPinMap[otherPin] = *this;
        }
    }
    else
        throw std::exception();
}

void nts::Component::dump() const
{
    speach::disp(m_type + " - " + m_name);
    speach::disp("input(s):");
    for (auto &[_, cpt] : m_inputPinMap)
        speach::disp(reinterpret_cast<nts::Component&>(cpt->get()).m_name + ": " + to_string(m_state));
    speach::disp("output(s):");
    for (auto &[_, cpt] : m_outputPinMap)
        speach::disp(reinterpret_cast<nts::Component&>(cpt->get()).m_name + ": " + to_string(m_state));
    speach::disp("");
}

void nts::Component::simulate(std::size_t tick)
{
    (void)tick;
}