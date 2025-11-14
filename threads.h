#pragma once
#include <latch>

void thread1_func(std::latch& latch_a, std::latch& latch_b);
void thread2_func(std::latch& latch_a, std::latch& latch_c);
void thread3_func(std::latch& latch_c);
void thread4_func(std::latch& latch_a, std::latch& latch_d);
void thread5_func(std::latch& latch_d);
void thread6_func(std::latch& latch_b);

