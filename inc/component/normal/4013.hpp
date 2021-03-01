/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4013.hpp
*/

#ifndef __4013_H__
#define __4013_H__

#include "../Component.hpp"

namespace nts
{

    class Component4013 :
        public Component
    {

        public:
            Component4013(const std::string& name, nts::Tristate state);
            ~Component4013() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4013_H__