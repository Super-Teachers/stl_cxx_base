
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

int main(int argc, char** argv) {
    std::vector<std::unique_ptr<int>> pointers;

    std::generate_n(
        std::back_inserter(pointers), 10,
        []() -> std::unique_ptr<int> { return std::make_unique<int>(10); });

    //for (auto v : pointers) {
        //std::cout << *v << std::endl;
    //}
}
