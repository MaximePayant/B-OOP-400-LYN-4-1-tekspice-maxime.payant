/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** console.hpp
*/

#ifndef SPEACH_HPP
#define SPEACH_HPP

#include <iostream>

namespace speach
{

    inline void disp(const std::string& str, const std::string& f = "")
    {
        std::cout << (f != "" ? f + " : " : "") << str << std::endl;
    }

    inline void error(const std::string& str, const std::string& f = "")
    {
        std::cerr << (f != "" ? f + " : " : "") << str << std::endl;
    }

}

#endif // SPEACH_HPP