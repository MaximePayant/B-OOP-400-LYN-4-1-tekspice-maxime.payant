/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** nts.hpp
*/

#ifndef NTS_HPP
#define NTS_HPP

#include <stack>
#include <unordered_map>
#include <memory>

#include <iostream>

#include "component/AComponent.hpp"

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

    class System
    {

        private:
            static std::unordered_map<std::string, std::unique_ptr<nts::IComponent> (*)()> m_createFunc;

            std::size_t chooseId;
            std::stack<std::size_t> freeId;
            std::unordered_map<std::size_t, std::unique_ptr<IComponent>> m_componentMap;

        public:
            System();
            ~System() = default;

            std::unique_ptr<IComponent> createComponent(const std::string &type);
            void print() { std::cout << m_componentMap.size() << std::endl; };


    }; // class System

    static System system;

} // namespace nts

#endif // NTS_HPP