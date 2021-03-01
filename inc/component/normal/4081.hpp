/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4081.hpp
*/

#ifndef __4081_H__
#define __4081_H__

#include "../Component.hpp"

namespace nts
{

    class Component4081 :
        public Component
    {

        public:
            Component4081(const std::string& name, nts::Tristate state);
            ~Component4081() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4081_H__