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

void read2() {
    std::vector<float> floats;
    std::size_t len;
    std::cin >> len;
    print(floats);

    std::copy_n(std::istream_iterator<float>(std::cin), len,
                std::back_inserter(floats));
    print(floats, std::cout);
}

std::vector<float> read(std::size_t N) {
    std::vector<float> res;
    std::generate_n(std::back_inserter(res), N, []() {
        float f;
        std::cin >> f;
        return f;
    });

    return res;
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
    std::size_t N;
    std::cin >> N;
    const auto v = read(N);
    std::cout << calculate(v) << "\n";
    return EXIT_SUCCESS;
}
