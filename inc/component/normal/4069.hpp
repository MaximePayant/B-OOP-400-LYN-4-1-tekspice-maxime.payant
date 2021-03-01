/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4069.hpp
*/

#ifndef __4069_H__
#define __4069_H__

#include "../Component.hpp"

namespace nts
{

    class Component4069 :
        public Component
    {

        public:
            Component4069(const std::string& name, nts::Tristate state);
            ~Component4069() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4069_H__