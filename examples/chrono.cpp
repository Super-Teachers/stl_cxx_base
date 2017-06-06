#include <chrono>
#include <iostream>

int main(int argc, char *argv[]) {
    namespace chr = std::chrono;
    auto hours = chr::hours(10);
    auto ten_seconds = chr::seconds(10);
    auto miliseconds = chr::duration_cast<chr::milliseconds>(ten_seconds);
    std::cout << miliseconds.count() << std::endl;
    miliseconds  = chr::duration_cast<chr::milliseconds>(hours);
    std::cout << miliseconds.count() << std::endl;
    return 0;
}
