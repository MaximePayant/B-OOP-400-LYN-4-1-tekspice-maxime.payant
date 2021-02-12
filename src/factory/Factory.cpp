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
static std::unique_ptr<nts::IComponent> createComponentBis()
{
    return (static_cast<std::unique_ptr<nts::IComponent>>(std::make_unique<T>()));
}

std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)()> nts::Factory::m_createFunc = {
    {"template", createComponentBis<nts::Template>}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (m_createFunc.find(type) != m_createFunc.end()) {
        speach::disp("Create " + type + " !");
        return (m_createFunc[type]());
    }
    throw std::exception(); // Make nts exception
}