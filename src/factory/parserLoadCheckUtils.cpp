/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** parserLoadCheckUtils.cpp
*/

#include <fstream>
#include <error/Error.hpp>

#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Parser.hpp"
#include "../../inc/component/Component.hpp"
#include "../../inc/factory/Factory.hpp"

bool nts::Parser::checkState(nts::Parser::ParserState& pState,
                             const std::string& buffer) const
{
    if (buffer == ".chipsets:") {
        pState = CHIPSET;
        return (true);
    }
    else if (buffer == ".links:") {
        pState = LINK;
        return (true);
    }
    return (false);
}

void nts::Parser::checkLine(const nts::Parser::ParserState& pState,
                            const std::string& buffer,
                            int line)
{
    if (buffer.empty())
        return;
    if (std::count(buffer.begin(), buffer.end(), ' ') != 1)
        throw nts::Error("ERROR: Wrong format at line " + std::to_string(line) + " <" + buffer + ">");

    std::string firstArg = buffer.substr(0, buffer.find_first_of(' '));
    std::string secondArg = buffer.substr(buffer.find_first_of(' ') + 1);

    switch (pState) {
        case CHIPSET:
            createComponent(firstArg, secondArg, line);
            return;
        case LINK:
            linkComponent(firstArg, secondArg, line);
            return;
        case NONE:
            throw nts::Error("ERROR: Line " + std::to_string(line) + " <" + buffer + ">" + " must be misplace.");
    }
    throw nts::Error("ERROR: Line " + std::to_string(line) + " <" + buffer + ">" + " is not correct!");
}