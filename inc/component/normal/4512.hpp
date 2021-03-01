/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4512.hpp
*/

#ifndef __4512_H__
#define __4512_H__

#include "../Component.hpp"

namespace nts
{

    class Component4512 :
        public Component
    {

        public:
            Component4512(const std::string& name, nts::Tristate state);
            ~Component4512() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4512_H__