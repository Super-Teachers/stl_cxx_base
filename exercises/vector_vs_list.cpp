#include <benchmark/benchmark.h>
#include <algorithm>
#include <array>
#include <complex>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>

// how to run:
// clang-format off
// ../3rdParty/benchmark/tools/compare.py benchmarksfiltered ./exercises/benchmark_vector_vs_list "std::vector" ./exercises/benchmark_vector_vs_list "std::list"
// clang-format on

template <typename IntType>
IntType randomValue() {
    return {100};
}

template <typename Container>
Container randomValues(std::size_t size) {
    Container data;
    data.resize(size);

    std::random_device rd;
    std::default_random_engine engine{rd()};
    using distribution_t = typename std::conditional<
        std::is_integral<typename Container::value_type>::value,
        std::uniform_int_distribution<typename Container::value_type>,
        std::uniform_real_distribution<typename Container::value_type>>::type;
    distribution_t dist(
        std::numeric_limits<typename Container::value_type>::min(),
        std::numeric_limits<typename Container::value_type>::max());
    std::generate(data.begin(), data.end(),
                  [&dist, &engine]() { return dist(engine); });

    return data;
}

struct BigHeapData {
    BigHeapData() : BigHeapData(150) {}
    BigHeapData(double val) {
        complexs.reserve(1024);
        std::fill_n(complexs.begin(), 1024, std::complex<double>(val, val));
    }
    std::vector<std::complex<double>> complexs;
};

template <typename T>
using is_vector = std::is_same<std::vector<typename T::value_type>, T>;

template <typename Container>
void BM_push_backs(benchmark::State& state) {
    Container ctx;
    if constexpr (is_vector<Container>::value) {
        ctx.reserve(state.range(0));
    }

    while (state.KeepRunning()) {
        for (int i = state.range(0); i--;) {
            ctx.push_back(randomValue<typename Container::value_type>());
        }
    }
}

template <typename Container>
void BM_find_value(benchmark::State& state) {
    std::vector<typename Container::value_type> container;
    typename Container::value_type searchedValue = {};
    container = randomValues<std::vector<typename Container::value_type>>(
        state.range());
    searchedValue = container[0];
    std::shuffle(container.begin(), container.end(),
                 std::mt19937{std::random_device{}()});

    Container testedContainer;
    std::copy(container.begin(), container.end(),
              std::back_inserter(testedContainer));

    while (state.KeepRunning()) {
        for (const auto& v : testedContainer) {
            if (v == searchedValue) {
                benchmark::DoNotOptimize(v);
            }
        }
    }
}

template <typename Container>
void BM_random_replace(benchmark::State& state) {
    std::vector<typename Container::value_type> container;

    if constexpr (std::is_fundamental<typename Container::value_type>::value) {
        container = randomValues<std::vector<typename Container::value_type>>(
            state.range());
    } else {
        container.resize(state.range());
    }
    std::shuffle(container.begin(), container.end(),
                 std::mt19937{std::random_device{}()});

    Container testedContainer;
    std::copy(container.begin(), container.end(),
              std::back_inserter(testedContainer));
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<std::size_t> dist(0, state.range());

    const std::size_t randomIndex = dist(engine);

    while (state.KeepRunning()) {
        auto it = testedContainer.begin();
        std::advance(it, randomIndex);
        *it = dist(engine);
        benchmark::DoNotOptimize(it);
    }
}

auto startRange = 16 * 16 * 16;
auto stopRange = 8 << 16;

/// PUSH_BACKS
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<int>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<float>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<std::array<char, 1024>>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<BigHeapData>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<int>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<float>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<std::array<char, 1024>>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<BigHeapData>)
    ->Range(startRange, stopRange);

/// FIND VALUE
BENCHMARK_TEMPLATE(BM_find_value, std::vector<int>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_find_value, std::list<int>)->Range(startRange, stopRange);

/// RANDOM INSERT
BENCHMARK_TEMPLATE(BM_random_replace, std::vector<int>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_random_replace, std::vector<double>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_random_replace, std::vector<BigHeapData>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_random_replace, std::list<int>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_random_replace, std::list<double>)
    ->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_random_replace, std::list<BigHeapData>)
    ->Range(startRange, stopRange);

BENCHMARK_MAIN();
