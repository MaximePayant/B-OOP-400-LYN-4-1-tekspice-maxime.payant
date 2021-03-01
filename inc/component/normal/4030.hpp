/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4030.hpp
*/

#ifndef __4030_H__
#define __4030_H__

#include "../Component.hpp"

namespace nts
{

    class Component4030 :
        public Component
    {

        public:
            Component4030(const std::string& name, nts::Tristate state);
            ~Component4030() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4030_H__