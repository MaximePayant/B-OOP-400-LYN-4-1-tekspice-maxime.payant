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

#include "IComponent.hpp"

namespace nts
{

    class AComponent :
        public IComponent
    {

        private:
            const std::size_t m_id;
            const std::string m_type;
            const std::size_t m_inputCount;
            const std::size_t m_outputCount;

            Tristate m_state;
            std::map<std::size_t, std::size_t> m_pinMap;

        protected:
            AComponent(
                const std::size_t& id,
                const std::string& type,
                const std::size_t& inputCount,
                const std::size_t& outputCount);
            Tristate getStatut() const;

        public:
            ~AComponent() = default;

            Tristate compute(std::size_t pin) override;
            using IComponent::simulate;
            using IComponent::setLink;
            using IComponent::dump;

    };

}

#endif // NTS_ACOMPONENT_HPP