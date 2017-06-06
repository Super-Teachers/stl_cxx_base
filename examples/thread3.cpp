#include <chrono>
#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
    int a = 10;
    std::thread t{[]() {}};
    t = std::thread([](int a) {}, 10);

    t.join();
    return 0;
}
