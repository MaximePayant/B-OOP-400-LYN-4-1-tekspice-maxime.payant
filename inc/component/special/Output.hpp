/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Output.hpp
*/

#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "../Component.hpp"

namespace nts
{

    class Output :
        public Component
    {

        public:
            Output(const std::string& name, nts::Tristate state);
            ~Output() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __OUTPUT_H__