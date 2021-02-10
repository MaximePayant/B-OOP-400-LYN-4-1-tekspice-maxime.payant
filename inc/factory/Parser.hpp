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
            std::unordered_map<std::size_t, std::unique_ptr<nts::IComponent>> m_componentMap;
            std::size_t m_chooseId;
            std::stack<std::size_t> m_freeId;

            std::size_t recupId();

        public:
            Parser();
            ~Parser();

    };

} // namespace nts

#endif // NTS_PARSER_HPP