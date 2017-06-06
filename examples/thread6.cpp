#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
void fn(int& a) {
    std::cout << "message";
}

int main(int argc, char* argv[]) {
    int a = 10;
    std::thread t{fn, std::ref(a)};

    std::cout << "ttttttttttttttrrrrrrrrrrrrrrrr";
    std::cout << "ttttttttttttttrrrrrrrrrrrrrrrr";
    std::cout << "ttttttttttttttrrrrrrrrrrrrrrrr";

    std::cout << std::endl;
    t.join();
    return 0;
}
