/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4017.hpp
*/

#ifndef __4017_H__
#define __4017_H__

#include "../Component.hpp"

namespace nts
{

    class Component4017 :
        public Component
    {

        public:
            Component4017(const std::string& name, nts::Tristate state);
            ~Component4017() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4017_H__