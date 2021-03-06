/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Factory.hpp
*/

#ifndef NTS_FACTORY_HPP
#define NTS_FACTORY_HPP

#include <unordered_map>
#include <memory>

#include "../component/IComponent.hpp"

namespace nts
{

    class Factory
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)(const std::string&, nts::Tristate state)> m_createFunc;

        public:
            Factory() = default;
            ~Factory() = default;

            static std::unique_ptr<IComponent> createComponent(const std::string& type, const std::string& name, nts::Tristate state);

    }; // class Factory

} // namespace nts

#endif // NTS_FACTORY_HPP