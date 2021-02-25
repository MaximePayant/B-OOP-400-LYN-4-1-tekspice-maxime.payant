/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Clock.hpp
*/

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "../Component.hpp"

namespace nts
{

    class Clock :
        public Component
    {

        public:
            Clock(const std::string& name, nts::Tristate state);
            ~Clock() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __CLOCK_H__