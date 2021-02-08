/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

nts::AComponent::AComponent(const std::size_t& id,
                            const std::string& type,
                            const std::size_t& inputCount,
                            const std::size_t& outputCount) :
    m_id(id),
    m_type(type),
    m_inputCount(inputCount),
    m_outputCount(outputCount),
    m_state(nts::UNDEFINED)
{
    for (std::size_t ctr = 1; ctr <= inputCount + outputCount; ctr += 1)
        m_pinMap[ctr] = 0;
}

nts::Tristate nts::AComponent::getStatut() const
{
    return (m_state);
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_inputCount + m_outputCount)
        return (nts::UNDEFINED);
    return (nts::UNDEFINED);
    //return (m_pinMap[pin].getStatut());
}