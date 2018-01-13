#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include <cstdint>

int main(int argc, char* argv[]) {
    try {
        double number = 0, number2 = 0;
        std::cin.exceptions(std::ios_base::badbit);
        std::cin.exceptions(std::ios_base::failbit);
        std::cin >> number >> number2;
        std::cout << number + number2 << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "What = " << ex.what() << std::endl;
    }
}
