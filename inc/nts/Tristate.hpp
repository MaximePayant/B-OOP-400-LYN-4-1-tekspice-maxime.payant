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

inline nts::Tristate operator&&(const nts::Tristate& left, const nts::Tristate& right)
{
    if (left == nts::TRUE
        && right == nts::TRUE)
        return (nts::TRUE);
    if (left == nts::FALSE
        || right == nts::FALSE)
        return (nts::FALSE);
    return (nts::UNDEFINED);
}

inline nts::Tristate operator||(const nts::Tristate& left, const nts::Tristate& right)
{
    if (left == nts::TRUE
    || right == nts::TRUE)
        return (nts::TRUE);
    if (left == nts::FALSE
    || right == nts::FALSE)
        return (nts::FALSE);
    return (nts::UNDEFINED);
}

inline nts::Tristate operator!(const nts::Tristate& state)
{
    if (state == nts::UNDEFINED)
        return (nts::UNDEFINED);
    if (state == nts::TRUE)
        return (nts::FALSE);
    return (nts::TRUE);
}

inline std::string to_string(nts::Tristate value)
{
    if (value == nts::TRUE)
        return ("1");
    else if (value == nts::FALSE)
        return ("0");
    return ("U");
}

#endif // NTS_TRISTATE_HPP