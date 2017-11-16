#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <complex>
#include <numeric>
#include <random>
#include <benchmark/benchmark.h>


template<typename IntType> 
IntType randomValue()
{
    return {100};
}

struct BigHeapData {
    BigHeapData(double val )
    {
        complexs.reserve(1024);
        std::fill_n(complexs.begin(), 1024, std::complex<double>(val, val));
    }
    std::vector<std::complex<double>> complexs;

};

template<typename T> 
using is_vector = std::is_same<std::vector<typename T::value_type>, T>;
template<typename Container> void BM_push_backs(benchmark::State& state)
{
    Container ctx;
    if constexpr (is_vector<Container>::value) {
        ctx.reserve(state.range(0));
    }

    while(state.KeepRunning()) {
        for (int i = state.range(0); i--; ) {
            ctx.push_back(randomValue<typename Container::value_type>());
        }
    }
}

template<typename Container> void BM_find_value(benchmark::State& state)
{
    static std::vector<typename Container::value_type> container;
    if (container.empty()) {
        container.reserve(state.range());
        std::iota(container.begin(), container.end(), 0);
        std::shuffle(container.begin(), container.end(),  std::mt19937{std::random_device{}()});
    }

    static typename Container::value_type randomValue = 500;
}

auto startRange = 8;
auto stopRange = 8 << 16;

BENCHMARK_TEMPLATE(BM_push_backs, std::vector<int>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<float>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<std::array<char, 1024>>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::vector<BigHeapData>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<int>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<float>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<std::array<char, 1024>>)->Range(startRange, stopRange);
BENCHMARK_TEMPLATE(BM_push_backs, std::list<BigHeapData>)->Range(startRange, stopRange);

BENCHMARK_MAIN();

