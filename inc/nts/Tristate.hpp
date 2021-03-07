/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Tristate.hpp
*/

#ifndef NTS_TRISTATE_HPP
#define NTS_TRISTATE_HPP

#include <string>

namespace nts
{

    enum Tristate
    {

        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false

    }; // enum Tristate


} // namespace nts

#include "Tristate.inl"

#endif // NTS_TRISTATE_HPP