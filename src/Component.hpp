/*
** EPITECH PROJECT, 2021
** Component.hpp
** File description:
** 
*/

#ifndef NANO_COMPONENT
#define NANO_COMPONENT

#include "../inc/IComponent.hpp"

class Component : public nts::IComponent
{
public:

    nts::Tristate input1;
    nts::Tristate input2;
    nts::Tristate output;
    Component();
    void simulate(std::size_t tick) override;
    nts::Tristate compute(std::size_t pin) override;
    void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
    void dump() const override;
};


#endif //NANO_COMPONENT
