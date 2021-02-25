/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4001.hpp
*/

#ifndef __4001_H__
#define __4001_H__

#include "../Component.hpp"

namespace nts
{

    class Component4001 :
        public Component
    {

        public:
            Component4001(const std::string& name, nts::Tristate state);
            ~Component4001() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4001_H__