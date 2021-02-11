/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Template.hpp
*/

#ifndef NTS_TEMPLATE_HPP
#define NTS_TEMPLATE_HPP

#include "Component.hpp"

namespace nts
{

    class Template :
        public Component
    {

        public:
            Template(const std::string& name) : Component(name, "template", nts::UNDEFINED) {};
            ~Template() = default;

    }; // class Template

} // namespace nts

#endif // NTS_TEMPLATE_HPP