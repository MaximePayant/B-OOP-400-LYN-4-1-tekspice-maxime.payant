/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Template.hpp
*/

#ifndef NTS_TEMPLATE_HPP
#define NTS_TEMPLATE_HPP

#include "AComponent.hpp"

namespace nts
{

    class Template :
        public AComponent
    {

        public:
            Template() : AComponent(1, "template", 1, 1) {};
            ~Template() = default;

            void simulate(std::size_t tick) override { (void)tick; };
            Tristate compute(std::size_t pin) override { (void)pin; return (UNDEFINED); };
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override { (void)pin; (void)other; (void)otherPin; };
            void dump() const override {};

    }; // class Template

} // namespace nts

#endif // NTS_TEMPLATE_HPP