/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** main.cpp
*/

#include <fstream>

#include "console/speach.hpp"
#include "nts.hpp"

bool check_error(int ac, char *str)
{
    if (!str)
        return (speach::error("ERROR: Give you a filename as argument ?"), true);

    std::string filename(str);

    if (ac != 2)
        return (speach::error("ERROR: We need only one argument, thanks."), true);
    if (filename.size() < 5 ||
    filename.rfind(".nts", (filename.size() - 4)) != (filename.size() - 4))
        return (speach::error("ERROR: Give you a .nts file as argument ?"), true);
    if (!std::ifstream(filename))
        return (speach::error("ERROR: Are you sure that the file you given exist or can be read ?"), true);
    return (false);
}

int main(int ac, char **av)
{
    if (check_error(ac, av[1]))
        return (84);

    nts::Parser parser(av[1]);

    return (0);
}