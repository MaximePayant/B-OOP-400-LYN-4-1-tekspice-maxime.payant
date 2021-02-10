/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Parser.hpp
*/

#ifndef NTS_PARSER_HPP
#define NTS_PARSER_HPP

#include <stack>

#include "Factory.hpp"

namespace nts
{

    class Parser
    {

        private:
            enum ParserState {NONE, CHIPSET, LINK};

            std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> m_componentMap;

            bool checkState(nts::Parser::ParserState& pState, const std::string& buffer) const;
            bool checkLine(const nts::Parser::ParserState& pState, const std::string& buffer, int line);
            bool createComponent(const std::string& firstArg, const std::string& secondArg, int line);
            bool LinkComponent(const std::string& firstArg, const std::string& secondArg, int line);

        public:
            Parser(const std::string& filename);
            ~Parser() = default;

    };

} // namespace nts

#endif // NTS_PARSER_HPP