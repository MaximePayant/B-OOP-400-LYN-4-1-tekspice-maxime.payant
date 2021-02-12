/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** nts.cpp
*/

#include <fstream>
#include <iostream>
#include <algorithm>

#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Parser.hpp"

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
    }
    else if (!str.empty())
        str = "";
}

bool nts::Parser::createComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    if (m_componentMap.find(secondArg) != m_componentMap.end()) {
        speach::error("ERROR: There is already a component name <" + secondArg + ">. Check at line " + std::to_string(line));
        return (false);
    }
    m_componentMap[secondArg] = nts::Factory::createComponent(firstArg);
    return (true);
}

bool nts::Parser::LinkComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    (void) firstArg;
    (void) secondArg;
    (void) line;
    return (true);
}

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

bool nts::Parser::checkLine(const nts::Parser::ParserState& pState,
                            const std::string& buffer,
                            int line)
{
    if (std::count(buffer.begin(), buffer.end(), ' ') != 1) {
        speach::error("ERROR: Wrong format at line " + std::to_string(line) + " <" + buffer + ">");
        return (false);
    }

    std::string firstArg = buffer.substr(0, buffer.find_first_of(' '));
    std::string secondArg = buffer.substr(buffer.find_first_of(' ') + 1);

    switch (pState) {
        case CHIPSET:
            return (createComponent(firstArg, secondArg, line));
        case LINK:
            return (LinkComponent(firstArg, secondArg, line));
        case NONE:
            return (true);
    }
    return (false);
}

nts::Parser::Parser(const std::string& filename)
{
    std::ifstream file(filename);
    std::string buffer;
    ParserState pState;

    for (std::size_t line = 1; std::getline(file, buffer); line += 1) {
        format(buffer);
        if (buffer.empty())
            continue;
        std::cout << "<" << buffer << ">" << std::endl;
        if (checkState(pState, buffer))
            continue;
        if (checkLine(pState, buffer, line))
            continue;
        throw std::exception();
    }
    if (m_componentMap.empty())
        speach::error("ERROR: There is no component in your circuit !");
    std::cout << "List of component size : " << m_componentMap.size() << std::endl;
}