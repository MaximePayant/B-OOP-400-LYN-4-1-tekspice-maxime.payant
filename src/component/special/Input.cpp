/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Input.cpp
*/

#include "component/special/Input.hpp"

nts::Input::Input(const std::string& name, nts::Tristate state) :
    nts::Component(name, "input")
{
    m_pinMap[1] = {CptInfo::OUTPUT, state, std::nullopt};
}