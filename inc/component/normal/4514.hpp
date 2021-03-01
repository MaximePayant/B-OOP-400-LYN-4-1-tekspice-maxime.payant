/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4514.hpp
*/

#ifndef __4514_H__
#define __4514_H__

#include "../Component.hpp"

namespace nts
{

    class Component4514 :
        public Component
    {

        public:
            Component4514(const std::string& name, nts::Tristate state);
            ~Component4514() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4514_H__