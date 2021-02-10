/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** nts.cpp
*/

#include "nts.hpp"

std::size_t nts::recupId()
{
    static std::size_t chooseId;
    static std::stack<std::size_t> freeId;
    std::size_t newId;

    if (freeId.empty() == false) {
        newId = freeId.top();
        freeId.pop();
    } else
        newId = chooseId;
    chooseId += 1;
    return (newId);
}