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

void nts::Parser::createComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    if (m_componentMap.find(secondArg) != m_componentMap.end())
        throw nts::Error("ERROR: There is already a component name <" + secondArg + ">. Check at line " + std::to_string(line));
    m_componentMap[secondArg] = nts::Factory::createComponent(firstArg, secondArg);
}

void nts::Parser::linkComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    if (std::count(firstArg.begin(), firstArg.end(), ':') != 1
    && std::count(secondArg.begin(), secondArg.end(), ':') != 1)
        throw nts::Error("ERROR: Wrong format at line " + std::to_string(line) + " <" + firstArg + " " + secondArg + ">");

    std::string firstArgName = firstArg.substr(0, firstArg.find_first_of(':'));
    std::size_t firstArgPin = std::stoul(firstArg.substr(firstArg.find_first_of(':') + 1));
    std::string secondArgName = secondArg.substr(0, secondArg.find_first_of(':'));
    std::size_t secondArgPin = std::stoul(secondArg.substr(secondArg.find_first_of(':') + 1));

    m_componentMap[firstArgName].get()->setLink(firstArgPin, *m_componentMap[secondArgName], secondArgPin);
}

bool nts::Parser::checkState(nts::Parser::ParserState& pState,
                             const std::string& buffer) const
{
    if (buffer == ".chipsets:")
        return (pState = CHIPSET, true);
    else if (buffer == ".links:")
        return (pState = LINK, true);
    return (false);
}

bool nts::Parser::checkLine(const nts::Parser::ParserState& pState,
                            const std::string& buffer,
                            int line)
{
    if (std::count(buffer.begin(), buffer.end(), ' ') != 1)
        throw nts::Error("ERROR: Wrong format at line " + std::to_string(line) + " <" + buffer + ">");

    std::string firstArg = buffer.substr(0, buffer.find_first_of(' '));
    std::string secondArg = buffer.substr(buffer.find_first_of(' ') + 1);

    switch (pState) {
        case CHIPSET:
            createComponent(firstArg, secondArg, line);
            break;
        case LINK:
            linkComponent(firstArg, secondArg, line);
            break;
        case NONE:
            break;
    }
    return (true);
}

void nts::Parser::load(const std::string& filename)
{
    std::ifstream file(filename);
    std::string buffer;
    ParserState pState;

    for (std::size_t line = 1; std::getline(file, buffer); line += 1) {
        format(buffer);
        if (buffer.empty())
            continue;
        if (checkState(pState, buffer))
            continue;
        if (checkLine(pState, buffer, line))
            continue;
        throw nts::Error("Line : " + std::to_string(line) + " is not correct!");
    }
    if (m_componentMap.empty())
        speach::error("ERROR: There is no component in your circuit !");
}