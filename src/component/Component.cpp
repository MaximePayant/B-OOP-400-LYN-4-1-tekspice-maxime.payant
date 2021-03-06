/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.cpp
*/

#include <error/Error.hpp>
#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Parser.hpp"
#include "../../inc/component/Component.hpp"

nts::Component::Component(const std::string& name, const std::string& type) :
    m_name(name),
    m_type(type),
    m_tick(0)
{}

nts::Tristate nts::Component::compute(std::size_t pin)
{
    auto it = m_pinMap.find(pin);

    if (it == m_pinMap.end())
        throw nts::Error("ERROR: Pin [" + std::to_string(pin) +"] not found!");
    return (it->second.m_state);
}

void nts::Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Component& otherCpt = dynamic_cast<nts::Component&>(other);

    if (m_pinMap.count(pin)
    && otherCpt.m_pinMap.count(otherPin)) {
        if (m_pinMap[pin].m_type == otherCpt.m_pinMap[otherPin].m_type)
            throw nts::Error("ERROR: You can't link two Input or two Output.");
        m_pinMap[pin].m_component.emplace(otherCpt);
        m_pinMap[pin].m_linkedPin = otherPin;
        otherCpt.m_pinMap[otherPin].m_component.emplace(*this);
        otherCpt.m_pinMap[otherPin].m_linkedPin = pin;
    }
    else
        throw nts::Error("ERROR: Pin [" + std::to_string(pin) + "] or other pin ["
                                        + std::to_string(otherPin) + "] doesn't exist!");
}

void nts::Component::dump() const
{
    speach::disp(m_name + " - " + m_type);
    speach::disp("Link(s):");
    for (auto &[pin, cptInfo] : m_pinMap) {
        if (!cptInfo.m_component.has_value())
            continue;
        std::cout << "Pin " << pin
                  << (cptInfo.m_type ? " [OUTPUT]" : " [INPUT]") << ": "
                  << cptInfo.m_component.value().get().getName()
                  << " - " << cptInfo.m_component.value().get().getType()
                  << " {" << to_string(cptInfo.m_state) << "}" << std::endl;
    }
    speach::disp("");
}

void nts::Component::simulatePin(CptInfo& cpt, std::size_t tick)
{
    if (cpt.m_component.has_value()) {
        cpt.m_component.value().get().simulate(tick);
        cpt.m_state = cpt.m_component.value().get().compute(cpt.m_linkedPin);
    }
}

void nts::Component::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}