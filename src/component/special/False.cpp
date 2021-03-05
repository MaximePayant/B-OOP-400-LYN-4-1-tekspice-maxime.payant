/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** False.cpp
*/

#include "component/special/False.hpp"

nts::False::False(const std::string& name, nts::Tristate state) :
    nts::Component(name, "false")
{
    (void)state;
    m_pinMap[1] = {CptInfo::OUTPUT, nts::FALSE, 0, std::nullopt};
}