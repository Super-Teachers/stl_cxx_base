#include <chrono>
#include <iostream>
#include <thread>

void thread_function() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
    std::cout << " Hello from thread " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char *argv[]) {
    std::thread t{thread_function};
    std::cout << " Hello from main" << std::this_thread::get_id() << " and " << t.get_id() << std::endl;
    return 0;
}
