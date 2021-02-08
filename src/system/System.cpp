/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** System.cpp
*/

#include "nts.hpp"

template <class T>
static std::unique_ptr<nts::IComponent> createComponentBis()
{
    return (static_cast<std::unique_ptr<nts::IComponent>>(std::make_unique<T>()));
}

std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)()> nts::System::m_createFunc = {
    {"template", createComponentBis<nts::Template>}
};

nts::System::System() :
    chooseId(0),
    freeId(),
    m_componentMap()
{}

std::unique_ptr<nts::IComponent> nts::System::createComponent(const std::string &type)
{
    if (m_createFunc.find(type) != m_createFunc.end()) {
        std::size_t newId;
        if (freeId.empty() == false) {
            newId = freeId.top();
            freeId.pop();
        } else
            newId = chooseId;
        m_componentMap[newId] = m_createFunc[type]();
        chooseId += 1;
        return (m_componentMap[newId]);
    }
    throw std::bad_alloc(); // Make nts execption
}