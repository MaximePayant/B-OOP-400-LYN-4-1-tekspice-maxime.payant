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

        private:
            bool m_needChange;
            nts::Tristate m_waitingState;

        public:
            Clock(const std::string& name, nts::Tristate state);
            ~Clock() = default;

            void simulate(std::size_t tick) override;

            friend Core;

    };

}

#endif // __CLOCK_H__