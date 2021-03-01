/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4512.cpp
*/

#include "component/normal/4512.hpp"

nts::Component4512::Component4512(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4512")
{
    (void)state;
}

void nts::Component4512::simulate(std::size_t tick)
{
}