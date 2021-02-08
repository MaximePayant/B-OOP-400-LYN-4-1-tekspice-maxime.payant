/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IComponent.hpp
*/

#ifndef NTS_ICOMPONENT_HPP
#define NTS_ICOMPONENT_HPP

#include <cstddef>

#include "../nts/Tristate.hpp"

namespace nts
{

    class IComponent
    {

        public:
            virtual ~IComponent () = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;

    }; // class IComponent

} // namespace nts

#endif // NTS_ICOMPONENT_HPP
