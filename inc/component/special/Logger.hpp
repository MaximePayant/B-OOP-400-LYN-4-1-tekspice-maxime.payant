/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Logger.hpp
*/

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "../Component.hpp"

namespace nts
{

    class Logger :
        public Component
    {

        public:
            Logger(const std::string& name, nts::Tristate state);
            ~Logger() = default;

            void simulate(std::size_t tick) override;

    };

}

#endif // __LOGGER_H__