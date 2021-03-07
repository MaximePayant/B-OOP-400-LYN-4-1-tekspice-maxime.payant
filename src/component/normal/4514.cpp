/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4514.cpp
*/

#include "component/normal/4514.hpp"

nts::Component4514::Component4514(const std::string& name, nts::Tristate state) :
    nts::Component(name, "4514")
{
    (void)state;
    m_pinMap[1] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[12] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[21] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[22] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[23] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[24] = {CptInfo::INPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[4] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[8] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[9] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[13] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[14] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[16] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[17] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[18] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[19] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[20] = {CptInfo::OUTPUT, nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component4514::simulate(std::size_t tick)
{
    if (tick != 0) {
        if (m_tick >= tick)
            return;
        m_tick += 1;
    }
}