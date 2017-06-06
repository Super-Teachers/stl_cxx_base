#include <iostream>
#include <memory>

int main(int argc, char** argv) {
    auto p = std::make_unique<char>('c');
    //std::unique_ptr<char> second = p;
}
