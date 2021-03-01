/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Factory.cpp
*/

#include <error/Error.hpp>
#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Factory.hpp"
#include "../../inc/component/component.hpp"

template <class T>
static std::unique_ptr<nts::IComponent> createComponentBis(const std::string& name, nts::Tristate state)
{
    return (static_cast<std::unique_ptr<nts::IComponent>>(std::make_unique<T>(name, state)));
}

std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)(const std::string&, nts::Tristate state)> nts::Factory::m_createFunc = {
    {"2716", createComponentBis<nts::Component2716>},
    {"4001", createComponentBis<nts::Component4001>},
    {"4008", createComponentBis<nts::Component4008>},
    {"4013", createComponentBis<nts::Component4013>},
    {"4017", createComponentBis<nts::Component4017>},
    {"4030", createComponentBis<nts::Component4030>},
    {"4040", createComponentBis<nts::Component4040>},
    {"4069", createComponentBis<nts::Component4069>},
    {"4071", createComponentBis<nts::Component4071>},
    {"4081", createComponentBis<nts::Component4081>},
    {"4094", createComponentBis<nts::Component4094>},
    {"4512", createComponentBis<nts::Component4512>},
    {"4514", createComponentBis<nts::Component4514>},
    {"4801", createComponentBis<nts::Component4801>},
    {"logger", createComponentBis<nts::Logger>},
    {"false", createComponentBis<nts::False>},
    {"true", createComponentBis<nts::True>},
    {"output", createComponentBis<nts::Output>},
    {"input", createComponentBis<nts::Input>},
    {"clock", createComponentBis<nts::Clock>}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string& name, nts::Tristate state)
{
    if (m_createFunc.find(type) != m_createFunc.end())
        return (m_createFunc[type](name, state));
    throw nts::Error("Component not found!");
}