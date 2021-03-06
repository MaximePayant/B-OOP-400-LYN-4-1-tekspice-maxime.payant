/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** parserLoadUtils.cpp
*/

#include <fstream>
#include <error/Error.hpp>

#include "../../inc/console/speach.hpp"
#include "../../inc/factory/Parser.hpp"
#include "../../inc/component/Component.hpp"
#include "../../inc/factory/Factory.hpp"

static bool checkName_and_state(const std::string& buffer, std::string& name, nts::Tristate& state)
{
    std::size_t valuePos = buffer.find_first_of('(');
    std::size_t valueEndPos = buffer.find_last_of(')');

    if (valuePos != std::string::npos
    && valueEndPos != std::string::npos
    && valuePos < valueEndPos)
    {
        name = buffer.substr(valuePos + 1, valueEndPos - valuePos - 1);
        if (name == "0" || name == "1" || name == "U")
            state = (name == "1" ? nts::TRUE : (name == "0" ? nts::FALSE : nts::UNDEFINED));
        else
            return (false);
        name = buffer.substr(0, valuePos);
    }
    return (true);
}

void nts::Parser::createComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    std::string name = secondArg;
    nts::Tristate state = nts::UNDEFINED;

    if (!checkName_and_state(secondArg, name, state))
        throw nts::Error("ERROR: Wrong value at line " + std::to_string(line) + " between parenthesis. Must be 0, 1 or U.");
    else if (m_componentMap.find(name) != m_componentMap.end())
        throw nts::Error("ERROR: There is already a component name <" + secondArg + ">. Check at line " + std::to_string(line));
    m_componentMap[name] = nts::Factory::createComponent(firstArg, name, state);
}

static std::size_t getPin(std::string str, int line)
{
    if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
        throw nts::Error("ERROR: Line " + std::to_string(line) + " you must give a valid pin as argument.");
    return (std::stoul(str));
}

void nts::Parser::linkComponent(const std::string& firstArg, const std::string& secondArg, int line)
{
    if (std::count(firstArg.begin(), firstArg.end(), ':') != 1
    || std::count(secondArg.begin(), secondArg.end(), ':') != 1)
        throw nts::Error("ERROR: Wrong format at line " + std::to_string(line) + " <" + firstArg + " " + secondArg + ">");

    std::string firstArgName = firstArg.substr(0, firstArg.find_first_of(':'));
    std::size_t firstArgPin = getPin(firstArg.substr(firstArg.find_first_of(':') + 1), line);
    std::string secondArgName = secondArg.substr(0, secondArg.find_first_of(':'));
    std::size_t secondArgPin = getPin(secondArg.substr(secondArg.find_first_of(':') + 1), line);

    if (m_componentMap.find(firstArgName) == m_componentMap.end())
        throw nts::Error("ERROR: Wrong argument <" + firstArgName + ">. Component doesn't exist.");
    if (m_componentMap.find(secondArgName) == m_componentMap.end())
        throw nts::Error("ERROR: Wrong argument <" + secondArgName + ">. Component doesn't exist.");
    m_componentMap[firstArgName].get()->setLink(firstArgPin, *m_componentMap[secondArgName], secondArgPin);
}