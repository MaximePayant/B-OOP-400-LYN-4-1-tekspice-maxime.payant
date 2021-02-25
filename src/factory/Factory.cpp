/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Factory.cpp
*/

#include "../../inc/console/speach.hpp"

#include "../../inc/factory/Factory.hpp"
#include "../../inc/component/component.hpp"

template <class T>
static std::unique_ptr<nts::IComponent> createComponentBis(const std::string& name)
{
    return (static_cast<std::unique_ptr<nts::IComponent>>(std::make_unique<T>(name, nts::UNDEFINED)));
}

std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)(const std::string&)> nts::Factory::m_createFunc = {
    {"4001", createComponentBis<nts::Component4001>},
    {"false", createComponentBis<nts::False>},
    {"true", createComponentBis<nts::True>},
    {"output", createComponentBis<nts::Output>},
    {"input", createComponentBis<nts::Input>}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string& name)
{
    if (m_createFunc.find(type) != m_createFunc.end())
        return (m_createFunc[type](name));
    throw std::exception(); // Make nts exception
}