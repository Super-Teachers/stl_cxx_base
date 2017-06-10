#include <chrono>
#include <iostream>
#include <thread>

void thread_function() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1ms);
}

int main(int argc, char *argv[]) {
    //std::thread t{athread_function};

    //std::cout << std::boolalpha << t.joinable() << std::endl;
    std::thread two;
    two = std::thread([]() {});
    std::cout << std::boolalpha << two.joinable() << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    //two = std::move(t);
    //std::cout << std::boolalpha << t.joinable() << std::endl;
    //std::cout << std::boolalpha << two.joinable() << std::endl;
    //two.join();
    return 0;
}
