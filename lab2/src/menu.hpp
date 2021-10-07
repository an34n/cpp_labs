#pragma once

#include <iostream>
#include <limits>

#include "lib.hpp"

namespace Menu {
    void show(std::ostream& output) {
        output << "0. Show menu" << std::endl;
        output << "1. Create hypocycloid" << std::endl;
        output << "2. Set smaller radius" << std::endl;
        output << "3. Set coefficient(k = R/r)" << std::endl;
        output << "4. Set distance from rolling circle centre" << std::endl;
        output << "5. Get coefficient" << std::endl;
        output << "6. Get smaller radius" << std::endl;
        output << "7. Get larger radius" << std::endl;
        output << "8. Get hypocycloid's type" << std::endl;
        output << "9. Get a point" << std::endl;
        output << "10. Get curvative radius" << std::endl;
        output << "11. Get sectorial area" << std::endl;
        output << "12. Exit" << std::endl;
    }      

    template <typename T>
    T get_value(std::istream& input) {
        T new_value;
        bool correct_input = true;
        do {
            try {
                input >> new_value;
                correct_input = true;
                if (input.fail()) {
                    throw "wrong input";
                }
            }
            catch (const char* &e) {
                if (input.bad() || input.eof()) {
                    std::cerr << "Found EOF, exiting the program" << std::endl;
                    exit(EXIT_FAILURE);
                }
                std::cerr << "Try again" << std::endl;
                correct_input = false;
                input.clear();
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (!correct_input);
        return new_value;
    }
}