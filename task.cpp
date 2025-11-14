#include "task.h"
#include <syncstream>
#include <iostream>

void f(char action, int index) {
    std::osyncstream(std::cout)
        << "З набору " << action << " виконано дію " << index << ".\n";
}