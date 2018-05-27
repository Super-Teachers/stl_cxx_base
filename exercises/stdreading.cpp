#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

float doSomething(const std::vector<float>& v, bool isSorted) {
    return std::accumulate(v.begin(), v.end(), isSorted ? 0 : 1,
                           [&isSorted](auto l, auto r) {
                               if (isSorted)
                                   return l + r;
                               else
                                   return l * r;
                           });
}

int main(int argc, char* argv[]) {
    std::size_t N;
    std::cout << "Podaj N liczb" << std::endl;
    std::cin >> N;

    std::vector<float> vec;
    vec.reserve(N);
    std::generate_n(std::back_inserter(vec), N, []() {
        float number;
        std::cin >> number;
        return number;
    });

    std::cout << doSomething(vec, std::is_sorted(vec.begin(), vec.end()))
              << std::endl;

    return 0;
}
