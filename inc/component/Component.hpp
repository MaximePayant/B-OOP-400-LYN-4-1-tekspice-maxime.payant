/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.hpp
*/

#ifndef NTS_ACOMPONENT_HPP
#define NTS_ACOMPONENT_HPP

#include <map>
#include <string>
#include <optional>
#include <functional>
#include "IComponent.hpp"

namespace nts
{

    class Component :
        public IComponent
    {

        protected:
            const std::string m_name;
            const std::string m_type;

            Tristate m_state;
            std::map<std::size_t, std::optional<std::reference_wrapper<IComponent>>> m_inputPinMap;
            std::map<std::size_t, std::optional<std::reference_wrapper<IComponent>>> m_outputPinMap;

            Component(const std::string& name, const std::string& type, Tristate state);

        public:
            ~Component() = default;

            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick);
            void dump() const;

    };

}

#endif // NTS_ACOMPONENT_HPP