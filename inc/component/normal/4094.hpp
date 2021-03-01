/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4094.hpp
*/

#ifndef __4094_H__
#define __4094_H__

#include "../Component.hpp"

namespace nts
{

    class Component4094 :
        public Component
    {

        public:
            Component4094(const std::string& name, nts::Tristate state);
            ~Component4094() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4094_H__