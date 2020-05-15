#include <iostream>
#include "datenstruktur.hpp"
using namespace std;

int main() {
    Heap<int> heap_variable(4);
    heap_variable.insert(1);
    heap_variable.insert(9);
    heap_variable.insert(10);
}