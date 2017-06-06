#include <iostream>
#include <memory>

struct Wrapper {
    Wrapper(std::unique_ptr<int> ptr) : _value(std::move(ptr)) {}
    void print() { std::cout << *_value << std::endl; }
   private:
    const std::unique_ptr<int> _value;
};

int main(int argc, char** argv) {
    Wrapper w(std::make_unique<int>(10));
    w.print();
}
