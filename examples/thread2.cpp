#include <chrono>
#include <iostream>
#include <thread>

void thread_function(int a) { std::cout << a << std::endl; }
int main(int argc, char *argv[]) {
    int a = 10;
    std::thread t{thread_function, a};
    a += 11;
    std::cout << a << std::endl;

    t.join();
    return 0;
}
