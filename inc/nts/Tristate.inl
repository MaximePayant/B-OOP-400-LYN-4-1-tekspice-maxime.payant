/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Tristate.inl
*/

#include "Tristate.hpp"

inline nts::Tristate operator^(const nts::Tristate& left, const nts::Tristate& right)
{
    if ((left == nts::TRUE && right == nts::TRUE)
    || (left == nts::FALSE && right == nts::FALSE))
        return (nts::FALSE);
    if ((left == nts::TRUE && right == nts::FALSE)
    || (left == nts::FALSE && right == nts::TRUE))
        return (nts::TRUE);
    return (nts::UNDEFINED);
}

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
    if (left == nts::UNDEFINED
    || right == nts::UNDEFINED)
        return (nts::UNDEFINED);
    return (nts::FALSE);
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