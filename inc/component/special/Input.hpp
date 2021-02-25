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

        public:
            Input(const std::string& name, nts::Tristate state);
            ~Input() = default;

    }; // class Input

} // namespace nts

#endif // __INPUT_H__