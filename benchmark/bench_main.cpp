#include <benchmark/benchmark.h>

#include "../src/RC4.h"
#include "../src/RC4.cpp"
#include "../src/FileIO.h"
#include "../src/FileIO.cpp"

std::string content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse orci magna, eleifend eu porta vel, rhoncus sit amet arcu.";
int threads         = 4;
std::string key     = "banana";

FileIO fileIO;

static void readFile(benchmark::State& state) {

    for (auto _ : state) {
        fileIO.read("fileHard.txt");
    }
}

static void cypher(benchmark::State& state) {

    std::string content = fileIO.read("fileHard.txt");
    RC4 rc4(key, content, threads);
    rc4.KSA();

    for (auto _ : state) {
        rc4.PRGA();
    }
}

BENCHMARK(readFile);
BENCHMARK(cypher);

BENCHMARK_MAIN();
