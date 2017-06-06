#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10ms);
    return 0;
}
