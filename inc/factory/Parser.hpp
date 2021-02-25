/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Parser.hpp
*/

#ifndef NTS_PARSER_HPP
#define NTS_PARSER_HPP

#include <map>
#include <memory>
#include <string>

#include "../component/IComponent.hpp"
#include "../../inc/core/Core.hpp"

namespace nts
{

    class Parser
    {

        private:
            enum ParserState {CHIPSET, LINK, NONE};

            std::map<std::string, std::unique_ptr<nts::IComponent>> m_componentMap;

            bool checkState(ParserState& pState, const std::string& buffer) const;
            void checkLine(const ParserState& pState, const std::string& buffer, int line);
            void createComponent(const std::string& firstArg, const std::string& secondArg, int line);
            void linkComponent(const std::string& firstArg, const std::string& secondArg, int line);

        public:
            Parser() = default;
            ~Parser() = default;

            void load(const std::string& filename);

            std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator begin()
            { return (m_componentMap.begin()); }
            std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator end()
            { return (m_componentMap.end()); }
            std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator find(const std::string& key)
            { return (m_componentMap.find(key)); }

    };

    extern Parser parser;

} // namespace nts

#endif // NTS_PARSER_HPP