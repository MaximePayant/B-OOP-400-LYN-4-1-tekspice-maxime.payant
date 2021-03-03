/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** False.hpp
*/

#ifndef __FALSE_H__
#define __FALSE_H__

#include "../Component.hpp"

namespace nts
{

    class False :
        public Component
    {

        private:
            bool m_needChange;
            nts::Tristate m_waitingState;

        public:
            False(const std::string& name, nts::Tristate state);
            ~False() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __FALSE_H__