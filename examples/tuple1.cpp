#include <iostream>
#include <tuple>
#include <utility>

constexpr auto cast_to_all(int value)
    -> decltype(std::make_tuple(int(), double(), float())) {
    return std::make_tuple(value, static_cast<double>(value),
                           static_cast<float>(value));
}

int main(int argc, char **argv) {
    std::cout << std::get<0>(cast_to_all(10)) << std::endl;
}
