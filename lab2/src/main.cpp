#include "lib.hpp"
#include "menu.hpp"

int main() {
    Menu::show(std::cout);
    Curves::Hypocycloid hypocycloid;
    while (true) {
        int cmd = Menu::get_value<int>(std::cin);
        switch (cmd) {
            case 0:
                Menu::show(std::cout);
                break;
            case 1: {
                std::cout << "1. Use r, k and d" << std::endl;
                std::cout << "2. Use r and k" << std::endl;
                int cmd1 = Menu::get_value<int>(std::cin);
                std::cout << "Enter smaller radius -> ";
                double r = Menu::get_value<double>(std::cin);
                std::cout << std::endl << "Enter coefficient -> ";
                double k = Menu::get_value<double>(std::cin);
                if (cmd1 == 1) {
                    std::cout << std::endl << "Enter distance -> ";
                    double d = Menu::get_value<double>(std::cin);
                    try {
                        hypocycloid = Curves::Hypocycloid(r, k, d);
                    } catch (const char* &e) {
                        std::cerr << e << std::endl;
                    }
                } else {
                    try {
                        hypocycloid = Curves::Hypocycloid(r, k);
                    } catch (const char* &e) {
                        std::cerr << e << std::endl;
                    }
                }
                std::cout << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter new smaller radius -> ";
                double new_r = Menu::get_value<double>(std::cin);
                try {
                    hypocycloid.set_r(new_r);
                } catch (const char* &e) {
                    std::cerr << e << std::endl;
                }
                std::cout << std::endl;
                break; 
            }
            case 3: {
                std::cout << "Enter new coefficient -> ";
                double new_k = Menu::get_value<double>(std::cin);
                try {
                    hypocycloid.set_k(new_k);
                } catch (const char* &e) {
                    std::cerr << e << std::endl;
                }
                std::cout << std::endl;
                break;
            }
            case 4: {
                std::cout << "Enter new distance -> ";
                double new_d = Menu::get_value<double>(std::cin);
                try {
                    hypocycloid.set_d(new_d);
                } catch (const char* &e) {
                    std::cerr << e << std::endl;
                }
                std::cout << std::endl;
                break;
            }
            case 5:
                std::cout << "K = " << hypocycloid.get_K() << std::endl;
                break;
            case 6:
                std::cout << "Smaller radius = " << hypocycloid.get_SR() << std::endl;
                break;
            case 7:
                std::cout << "Larger radius = " << hypocycloid.get_LR() << std::endl;
                break;
            case 8:
                std::cout << "Type: " << hypocycloid.get_type() << " hypocycloid" << std::endl;
                break;
            case 9: {
                std::cout << "Enter angle value -> ";
                double angle = Menu::get_value<double>(std::cin);
                std::cout << std::endl << "Point: " << hypocycloid.get_point(angle) << std::endl;
                break;
            }
            case 10: {
                std::cout << "Enter angle value -> ";
                double angle = Menu::get_value<double>(std::cin);
                std::cout << std::endl << "Curvative radius: " << hypocycloid.get_curvative_radius(angle) << std::endl;
                break;
            }
            case 11: {
                std::cout << "Enter angle value -> ";
                double angle = Menu::get_value<double>(std::cin);
                std::cout << std::endl << "Sectorial area: " << hypocycloid.get_sectorial_area(angle) << std::endl;
                break;
            }
            case 12:
                exit(EXIT_SUCCESS);
        }
    }
    return 0;
}