// thread4.cpp
#include <chrono>
#include <iostream>
#include <thread>

void fn(int& a) { a = 20; }

int main(int argc, char* argv[]) {
    int a = 10;
    std::thread t{fn, std::ref(a)};
    a += 11;

    t.join();
    std::cout << a << std::endl;
    return 0;
}
