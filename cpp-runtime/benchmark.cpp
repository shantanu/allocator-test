#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>

const int NUM_ALLOCATIONS = 1000000;
const int MAX_ALLOCATION_SIZE = 1024;

std::vector<void*> ptrs(NUM_ALLOCATIONS);

void benchmark_allocator() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, MAX_ALLOCATION_SIZE);

    auto start = std::chrono::high_resolution_clock::now();

    // Allocate
    for (int i = 0; i < NUM_ALLOCATIONS; ++i) {
        ptrs[i] = malloc(dis(gen));
    }

    // Shuffle to randomize deallocation order
    std::shuffle(ptrs.begin(), ptrs.end(), gen);

    // Deallocate
    for (int i = 0; i < NUM_ALLOCATIONS; ++i) {
        free(ptrs[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    std::cout << "Time taken: " << diff.count() << " seconds" << std::endl;
}

int main() {
    benchmark_allocator();
    return 0;
}