/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** False.hpp
*/

#ifndef __FALSE_H__
#define __FALSE_H__

#include "../Component.hpp"

namespace nts
{

    class False :
        public Component
    {

        public:
            False(const std::string& name, nts::Tristate state);
            ~False() = default;

    };

}

#endif // __FALSE_H__