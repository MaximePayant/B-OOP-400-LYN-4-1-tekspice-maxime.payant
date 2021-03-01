/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4008.hpp
*/

#ifndef __4008_H__
#define __4008_H__

#include "../Component.hpp"

namespace nts
{

    class Component4008 :
        public Component
    {

        public:
            Component4008(const std::string& name, nts::Tristate state);
            ~Component4008() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4008_H__