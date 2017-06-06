#include <iostream>
#include <memory>

template <typename T>
void print_unique(const std::unique_ptr<T>& ptr) {
    std::cout << *ptr << std::endl;
}

std::unique_ptr<int> create_unique(int value) {
    return std::make_unique<int>(value);
}

int main(int argc, char** argv) {
    auto p = std::make_unique<char>('c');
    print_unique(std::make_unique<int>(5));
    auto u = create_unique(10);
}
