/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** nts.cpp
*/

#include <fstream>
#include <error/Error.hpp>

#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Parser.hpp"
#include "../../inc/component/Component.hpp"
#include "../../inc/factory/Factory.hpp"

nts::Parser nts::parser;

static void format(std::string& str)
{
    std::size_t comPos = str.find_first_of('#', 0);
    std::size_t firstPos = 0;
    std::size_t lastPos = 0;

    if (comPos != str.npos)
        str.erase(comPos, str.size() - comPos);
    firstPos = str.find_first_not_of(" \t");
    lastPos = str.find_last_not_of(" \t");
    if (firstPos != str.npos && lastPos != str.npos) {
        str = str.substr(firstPos, lastPos - firstPos + 1);
        firstPos = str.find_first_of(" \t");
        while (firstPos != str.npos) {
            lastPos = str.find_first_not_of(" \t", firstPos);
            str.replace(firstPos, lastPos - firstPos, " ");
            firstPos = str.find_first_of(" \t", firstPos + 1);
        }
    } else if (!str.empty())
        str = "";
}

void nts::Parser::load(const std::string& filename)
{
    std::ifstream file(filename);
    std::string buffer;
    ParserState pState;

    for (std::size_t line = 1; std::getline(file, buffer); line += 1) {
        format(buffer);
        if (!checkState(pState, buffer))
            checkLine(pState, buffer, line);
    }
    if (m_componentMap.empty())
        speach::error("ERROR: There is no component in your circuit !");
}