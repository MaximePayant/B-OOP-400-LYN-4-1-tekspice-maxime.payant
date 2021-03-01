/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4071.hpp
*/

#ifndef __4071_H__
#define __4071_H__

#include "../Component.hpp"

namespace nts
{

    class Component4071 :
        public Component
    {

        public:
            Component4071(const std::string& name, nts::Tristate state);
            ~Component4071() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4071_H__