#include "threads.h"
#include "task.h"
#include <thread>
#include <latch>
#include <syncstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    system("chcp 65001");
    osyncstream(cout) << "Обчислення розпочато.\n";

    latch latch_a(1);  
    latch latch_b(1);  
    latch latch_c(1);  
    latch latch_d(1);  

    vector<thread> threads;

    threads.emplace_back(thread1_func, ref(latch_a), ref(latch_b));
    threads.emplace_back(thread2_func, ref(latch_a), ref(latch_c));
    threads.emplace_back(thread3_func, ref(latch_c));
    threads.emplace_back(thread4_func, ref(latch_a), ref(latch_d));
    threads.emplace_back(thread5_func, ref(latch_d));
    threads.emplace_back(thread6_func, ref(latch_b));

    for (auto& t : threads) {
        t.join();
    }

    osyncstream(std::cout) << "Обчислення завершено.\n";

    return 0;
}