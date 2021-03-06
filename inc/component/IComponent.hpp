/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IComponent.hpp
*/

#ifndef NTS_ICOMPONENT_HPP
#define NTS_ICOMPONENT_HPP

#include <string>
#include <cstddef>

#include "../nts/Tristate.hpp"

namespace nts
{

    class IComponent
    {

        public:
            virtual ~IComponent () = default;

            virtual const std::string& getName() const = 0;
            virtual const std::string& getType() const = 0;

            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual void dump() const = 0;

    }; // class IComponent

} // namespace nts

#endif // NTS_ICOMPONENT_HPP
