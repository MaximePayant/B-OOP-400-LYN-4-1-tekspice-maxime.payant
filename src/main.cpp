/*
** EPITECH PROJECT, 2021
** main.cpp.c
** File description:
** 
*/

#include "core/Core.hpp"

int main()
{
    Core core;

    while (core.isInCore())
        core.getValue();
    return (0);
}