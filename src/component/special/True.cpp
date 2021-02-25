/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** True.cpp
*/

#include "component/special/True.hpp"

nts::True::True(const std::string& name, nts::Tristate state) :
    nts::Component(name, "true")
{
    (void)state;
    m_pinMap[1] = {CptInfo::OUTPUT, nts::TRUE, 0, std::nullopt};
}