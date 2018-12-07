#include <benchmark/benchmark.h>

#include "../src/my_code.h"

using namespace my_namespace;


static void sayHello(benchmark::State& state) {
    Hello hello;

    for (auto _ : state) {
        hello.hello();
    }
}

BENCHMARK(sayHello);

BENCHMARK_MAIN();
