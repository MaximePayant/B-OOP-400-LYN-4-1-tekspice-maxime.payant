/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4008.cpp
*/

#include "component/normal/4008.hpp"

nts::Component4008::Component4008(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4008")
{
    (void)state;
}

void nts::Component4008::simulate(std::size_t tick)
{
}