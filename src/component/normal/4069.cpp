/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4069.cpp
*/

#include "component/normal/4069.hpp"

nts::Component4069::Component4069(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4069")
{
    (void)state;
}

void nts::Component4069::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}