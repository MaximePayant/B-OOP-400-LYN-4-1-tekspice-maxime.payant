/*
** EPITECH PROJECT, 2021
** Component4011.hpp.h
** File description:
** 
*/

#ifndef B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_COMPONENT4011
#define B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_COMPONENT4011

#include <Component.hpp>

namespace nts
{
    class Component4011 : public Component
    {
    public:
        Component4011(const std::string& name, nts::Tristate state);
        ~Component4011() = default;

        void simulate(std::size_t tick) override;
    };
}


#endif //B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_COMPONENT4011
