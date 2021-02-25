/*
** EPITECH PROJECT, 2021
** Core.hpp.h
** File description:
**
*/

#ifndef B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE
#define B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE

#include <string>

namespace nts
{

    class Core
    {

        private:
            void display();
            void setInput(std::string var, std::string value);
            void simulate();
            void loop();
            void dump();

        public:
            static std::size_t tick;
            static bool inCore;
            static bool isLoop;

            Core();
            ~Core() = default;

            void getValue();

    }; // class Core

} // namespace nts


#endif //B_OOP_400_LYN_4_1_TEKSPICE_GUILLAUME_SOISSON_CORE
