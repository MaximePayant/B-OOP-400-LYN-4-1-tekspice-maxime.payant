/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 2716.cpp
*/

#include "component/normal/2716.hpp"

nts::Component2716::Component2716(const std::string& name, nts::Tristate state) :
    nts::Component(name, "2716")
{
    (void)state;
    m_pinMap[1]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[2]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[3]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[4]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[5]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[6]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[7]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[8]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[19]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[22]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[23]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[9]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[10]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[11]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[13]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[14]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[15]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[16]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[17]  = {CptInfo::OUTPUT,  nts::UNDEFINED, 0, std::nullopt};

    m_pinMap[18]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
    m_pinMap[20]  = {CptInfo::INPUT,  nts::UNDEFINED, 0, std::nullopt};
}

void nts::Component2716::simulate(std::size_t tick)
{
    if (m_tick >= tick)
        return;
    m_tick += 1;
}