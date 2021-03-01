/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4801.cpp
*/

#include "component/normal/4801.hpp"

nts::Component4801::Component4801(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4801")
{
    (void)state;
}

void nts::Component4801::simulate(std::size_t tick)
{
}