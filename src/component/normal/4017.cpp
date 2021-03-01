/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4017.cpp
*/

#include "component/normal/4017.hpp"

nts::Component4017::Component4017(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4017")
{
    (void)state;
}

void nts::Component4017::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}