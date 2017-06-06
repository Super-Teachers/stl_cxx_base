#include <chrono>
#include <iostream>
#include <thread>

void thread_function() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
}

int main(int argc, char *argv[]) {
    std::thread t{thread_function};

    std::cout << std::boolalpha << t.joinable() << std::endl;
    std::thread two;
    std::cout << std::boolalpha << two.joinable() << std::endl;
    two = std::move(t);
    std::cout << std::boolalpha << t.joinable() << std::endl;
    std::cout << std::boolalpha << two.joinable() << std::endl;
    two.join();
    return 0;
}
