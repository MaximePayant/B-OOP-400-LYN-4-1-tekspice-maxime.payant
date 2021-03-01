/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** 4801.hpp
*/

#ifndef __4801_H__
#define __4801_H__

#include "../Component.hpp"

namespace nts
{

    class Component4801 :
        public Component
    {

        public:
            Component4801(const std::string& name, nts::Tristate state);
            ~Component4801() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __4801_H__