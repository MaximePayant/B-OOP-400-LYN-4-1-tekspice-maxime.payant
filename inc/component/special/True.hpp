/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** True.hpp
*/

#ifndef __TRUE_H__
#define __TRUE_H__

#include "../Component.hpp"

namespace nts
{

    class True :
        public Component
    {

        public:
            True(const std::string& name, nts::Tristate state);
            ~True() = default;

    };

}

#endif // __TRUE_H__