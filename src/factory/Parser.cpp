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
    }
    else if (!str.empty())
        str = "";
}

bool nts::Parser::createComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    std::string name = secondArg;
    nts::Tristate state = nts::UNDEFINED;

    std::size_t valuePos = secondArg.find_first_of('(');
    std::size_t valueEndPos = secondArg.find_last_of(')');

    if (valuePos != std::string::npos
    && valueEndPos != std::string::npos
    && valuePos < valueEndPos) {
        name = secondArg.substr(valuePos + 1, valueEndPos - valuePos - 1);
        if (name == "1" || name == "2" || name == "U")
            state = (name == "1" ? nts::TRUE : (name == "0" ? nts::FALSE : nts::UNDEFINED));
        else
            throw std::exception();
        name = secondArg.substr(0, valuePos);
    }

    if (m_componentMap.find(name) != m_componentMap.end()) {
        speach::error("ERROR: There is already a component name <" + name + ">. Check at line " + std::to_string(line));
        return (false);
    }

    m_componentMap[name] = nts::Factory::createComponent(firstArg, name, state);
    return (true);
}

bool nts::Parser::linkComponent(const std::string& firstArg, const std::string& secondArg, int line)
{

    if (std::count(firstArg.begin(), firstArg.end(), ':') != 1
    && std::count(secondArg.begin(), secondArg.end(), ':') != 1) {
        speach::error("ERROR: Wrong format at line " + std::to_string(line) + " <" + firstArg + " " + secondArg + ">");
        return (false);
    }

    std::string firstArgName = firstArg.substr(0, firstArg.find_first_of(':'));
    std::size_t firstArgPin = std::stoul(firstArg.substr(firstArg.find_first_of(':') + 1));
    std::string secondArgName = secondArg.substr(0, secondArg.find_first_of(':'));
    std::size_t secondArgPin = std::stoul(secondArg.substr(secondArg.find_first_of(':') + 1));

    m_componentMap[firstArgName].get()->setLink(firstArgPin, *m_componentMap[secondArgName].get(), secondArgPin);
    return (true);
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
            return (linkComponent(firstArg, secondArg, line));
        case NONE:
            return (true);
    }
    return (false);
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
        throw std::exception();
    }
    if (m_componentMap.empty())
        speach::error("ERROR: There is no component in your circuit !");
}