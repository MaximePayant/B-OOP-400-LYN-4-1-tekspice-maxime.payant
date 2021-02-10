/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** nts.cpp
*/

#include "factory/Parser.hpp"

std::size_t nts::Parser::recupId()
{
    std::size_t newId;

    if (m_freeId.empty() == false) {
        newId = m_freeId.top();
        m_freeId.pop();
    } else
        newId = m_chooseId;
    m_chooseId += 1;
    return (newId);
}