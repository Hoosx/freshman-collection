#include <iostream>
#include <chrono>

#include "concurrent/thread_pool.h"

int main() {
    ThreadPool pool(4);
    auto result1 = pool.Enqueue([](int echo) { return echo; }, 42);
    auto result2 = pool.Enqueue(
        [](int time_out) {
            std::this_thread::sleep_for(std::chrono::seconds(time_out));
            std::cout << time_out << std::endl;
        },
        2);
    std::cout << result1.get() << std::endl;
}