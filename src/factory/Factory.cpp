/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Factory.cpp
*/

#include "console/speach.hpp"

#include "factory/Factory.hpp"
#include "component/component.hpp"

template <class T>
static std::unique_ptr<nts::IComponent> createComponentBis(const std::string& name)
{
    return (static_cast<std::unique_ptr<nts::IComponent>>(std::make_unique<T>(name)));
}

std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)(const std::string&)> nts::Factory::m_createFunc = {
    {"template", createComponentBis<nts::Template>}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string& name)
{
    if (m_createFunc.find(type) != m_createFunc.end()) {
        speach::disp("Create " + type + " !");
        return (m_createFunc[type](name));
    }
    throw std::exception(); // Make nts exception
}