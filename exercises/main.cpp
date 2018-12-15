#include <gtest/gtest.h>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

template <typename T>
void print(T&& t, std::ostream& os = std::cout) {
    if (std::begin(t) == std::end(t)) {
        os << "[]\n";
        return;
    }
    std::cout << "[";
    std::for_each(std::begin(t), std::end(t) - 1,
                  [&os](auto v) { os << v << ", "; });

    std::cout << *(std::end(t) - 1);
    std::cout << "]\n";
}

void printSpecial(const std::vector<std::uint8_t>& v) {
    auto old = std::cout.flags();
    std::cout << std::hex;
    for (auto c : v) {
        std::cout << std::setw(5) << std::left << std::showbase;
        std::cout.fill('_');
        std::cout << static_cast<int>(c) << ",";
    }
    std::cout << "\n";
    std::cout.setf(old);
}

std::vector<float> read2(int N) {
    std::vector<float> floats;

    std::copy_n(std::istream_iterator<float>(std::cin), N,
                std::back_inserter(floats));
    print(floats);
    return floats;
}

float calculate(const std::vector<float>& vec) {
    if (std::is_sorted(vec.begin(), vec.end())) {
        return std::accumulate(vec.begin(), vec.end(), 0.0f);
    } else {
        return std::accumulate(vec.begin(), vec.end(), 1.0f,
                               std::multiplies<float>());
    }
}

int main(int argc, char** argv) {
    // int N;
    // if ( std::cin >> N) {
    //}
    ////std::cin.exceptions(std::ios::badbit | std::ios::failbit);
    // try {
    // const auto v = read2(N);
    // std::cout << calculate(v) << "\n";
    //} catch (const std::exception& ex) {
    //}
    // return EXIT_SUCCESS;
    printSpecial(std::vector<std::uint8_t>{1, 2, 3});

    std::cout << 10;
    std::cout << std::endl;
}
