/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** input.hpp
*/

#ifndef __INPUT_H__
#define __INPUT_H__

#include "../Component.hpp"

namespace nts
{

    class Input :
        public Component
    {

        private:
            bool m_needChange;
            nts::Tristate m_waitingState;

        public:
            Input(const std::string& name, nts::Tristate state);
            ~Input() = default;

            void simulate(std::size_t tick) override;

        friend Core;

    }; // class Input

} // namespace nts

#endif // __INPUT_H__