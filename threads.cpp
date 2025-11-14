#include "threads.h"
#include "task.h"
#include <latch>

void execute_action(char action, int count) {
    for (int i = 1; i <= count; ++i) {
        f(action, i);
    }
}

void thread1_func(std::latch& latch_a, std::latch& latch_b) {
    execute_action('a', A);
    latch_a.count_down();

    execute_action('b', B);
    latch_b.count_down();

    execute_action('e', E);
}

void thread2_func(std::latch& latch_a, std::latch& latch_c) {
    latch_a.wait();
    execute_action('c', C);
    latch_c.count_down();
    execute_action('f', F);
}

void thread3_func(std::latch& latch_c) {
    latch_c.wait();
    execute_action('g', G);
}

void thread4_func(std::latch& latch_a, std::latch& latch_d) {
    latch_a.wait();
    execute_action('d', D);
    latch_d.count_down();
    execute_action('h', H);
}

void thread5_func(std::latch& latch_d) {
    latch_d.wait();
    execute_action('i', I);
}

void thread6_func(std::latch& latch_b) {
    latch_b.wait();
}