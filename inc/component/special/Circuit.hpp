/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Circuit.hpp
*/

#ifndef NTS_CIRCUIT_HPP
#define NTS_CIRCUIT_HPP

#include "../IComponent.hpp"

namespace nts
{

    class Circuit :
        public IComponent
    {

        public:
            Circuit();
            ~Circuit() = default;

            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

    };

} // namespace nts

#endif // NTS_CIRCUIT_HPP