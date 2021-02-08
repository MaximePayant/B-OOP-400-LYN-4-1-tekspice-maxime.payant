/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
#define ACOMPONENT_HPP

#include <map>
#include <string>

#include "IComponent.hpp"

namespace nts
{

    class AComponent :
        public IComponent
    {

        private:
            const std::size_t m_id;
            const std::string m_type;

            Tristate m_state;
            std::size_t m_inputCount;
            std::size_t m_outputCount;
            std::map<std::size_t, IComponent> m_componentMap;

        protected:
            AComponent(const std::size_t& id, const std::string& type);

        public:
            ~AComponent() = default;

            using IComponent::simulate;
            using IComponent::compute;
            using IComponent::setLink;
            using IComponent::dump;

    };

}

#endif // ACOMPONENT_HPP