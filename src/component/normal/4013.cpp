/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4013.cpp
*/

#include "component/normal/4013.hpp"

nts::Component4013::Component4013(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4013")
{
    (void)state;
}

void nts::Component4013::simulate(std::size_t tick)
{
}