#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
namespace {
std::mutex lock;
}
void fn(int& a) {
    lock.lock();
    a = 10;
    lock.unlock();
}

int main(int argc, char* argv[]) {
    int a = 10;
    std::thread t{fn, std::ref(a)};
    {
        std::lock_guard<decltype(lock)> g{lock};
        a += 15;
    }
    t.join();
    return 0;
}
