/*
** EPITECH PROJECT, 2021
** Error.hpp.h
** File description:
** 
*/

#ifndef B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_ERROR
#define B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_ERROR


#include <stdexcept>

class Error : public std::runtime_error
{
public:
    Error() = delete;
    Error(Error const&) = delete;
    Error(Error&&) = delete;
    Error& operator=(Error const&) = delete;
    Error& operator=(Error&&) = delete;
    explicit Error(std::string message);
    ~Error() override = default;
};


#endif //B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_ERROR
