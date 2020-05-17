#ifndef MIN_HEAP_CPP_TESTTREIBER_HPP
#define MIN_HEAP_CPP_TESTTREIBER_HPP

#include "datenstruktur.hpp"

class Testtreiber {
private:
// ---------- private Methoden ----------
    void test1(Heap<T>::Heap heap_variable);
    void test2();
    void test3();
    void test4();
    void test5();
    
public:
// ---------- public Methoden ----------
    explicit Testtreiber();
    ~Testtreiber();
    void execute_tests();
};

#endif //MIN_HEAP_CPP_TESTTREIBER_HPP