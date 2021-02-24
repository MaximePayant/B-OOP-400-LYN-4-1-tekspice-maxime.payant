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
            bool checkLine(const ParserState& pState, const std::string& buffer, int line);
            bool createComponent(const std::string& firstArg, const std::string& secondArg, int line);
            bool linkComponent(const std::string& firstArg, const std::string& secondArg, int line);

        public:
            Parser() = default;
            ~Parser() = default;

            void load(const std::string& filename);
        friend Core;
    };

    static Parser parser;

} // namespace nts

#endif // NTS_PARSER_HPP