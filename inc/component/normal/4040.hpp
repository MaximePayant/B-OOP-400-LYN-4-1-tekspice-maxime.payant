/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4040.hpp
*/

#ifndef __4040_H__
#define __4040_H__

#include "../Component.hpp"

namespace nts
{

    class Component4040 :
        public Component
    {

        public:
            Component4040(const std::string& name, nts::Tristate state);
            ~Component4040() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4040_H__