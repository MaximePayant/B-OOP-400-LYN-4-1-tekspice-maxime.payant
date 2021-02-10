/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.cpp
*/

#include "factory/Parser.hpp"
#include "component/Component.hpp"

nts::Component::Component(nts::Tristate state) :
    m_state(state)
{}

nts::Tristate nts::Component::getStatut() const
{
    return (m_state);
}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    auto it = m_inputPinMap.find(pin);

    if (it == m_inputPinMap.end())
        it = m_outputPinMap.find(pin);
    if (it == m_outputPinMap.end())
        throw std::exception();
    if (!it->second.has_value())
        throw std::exception();
    return (reinterpret_cast<nts::Component&>(it->second.value()).getStatut());
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