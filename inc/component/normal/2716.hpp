/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 2716.hpp
*/

#ifndef __2716_H__
#define __2716_H__

#include "../Component.hpp"

namespace nts
{

    class Component2716 :
        public Component
    {

        public:
            Component2716(const std::string& name, nts::Tristate state);
            ~Component2716() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __2716_H__