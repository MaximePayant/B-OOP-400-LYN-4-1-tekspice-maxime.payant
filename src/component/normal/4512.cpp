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
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[14] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4512::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
}