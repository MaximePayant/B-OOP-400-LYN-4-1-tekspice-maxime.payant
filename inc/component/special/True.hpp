/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** True.hpp
*/

#ifndef __TRUE_H__
#define __TRUE_H__

#include "../Component.hpp"

namespace nts
{

    class True :
        public Component
    {

        private:
            bool m_needChange;
            nts::Tristate m_waitingState;

        public:
            True(const std::string& name, nts::Tristate state);
            ~True() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __TRUE_H__