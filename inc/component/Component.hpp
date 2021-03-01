/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.hpp
*/

#ifndef NTS_ACOMPONENT_HPP
#define NTS_ACOMPONENT_HPP

#include <unordered_map>
#include <string>
#include <optional>
#include <functional>
#include "IComponent.hpp"
#include "../core/Core.hpp"

namespace nts
{


    class Component :
        public IComponent
    {

        protected:
            class CptInfo
            {
                public:
                    enum {INPUT, OUTPUT} m_type;
                    Tristate m_state;
                    std::size_t m_linkedPin;
                    std::optional<std::reference_wrapper<IComponent>> m_component;
            };

            const std::string m_name;
            const std::string m_type;

            std::unordered_map<std::size_t, CptInfo> m_pinMap;
            std::size_t m_tick;

            Component(const std::string& name, const std::string& type);

            void simulatePin(CptInfo cpt, std::size_t tick);

        public:
            ~Component() = default;

            const std::string& getName() const override { return (m_name); }
            const std::string& getType() const override { return (m_type); }

            Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick);
            void dump() const;

            friend Core;

    };

}

#endif // NTS_ACOMPONENT_HPP