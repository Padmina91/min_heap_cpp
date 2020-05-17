#ifndef MIN_HEAP_CPP_TESTTREIBER_HPP
#define MIN_HEAP_CPP_TESTTREIBER_HPP

#include "datenstruktur.hpp"

template <typename T>
class Testtreiber {
private:
// ---------- private Methoden Deklaration ----------
    void test1(Heap<T> heap_variable);
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

// ---------- private Methoden Implementierung ----------

template <typename T>
void Testtreiber<T>::test1(Heap<T> heap_variable) {


}

#endif //MIN_HEAP_CPP_TESTTREIBER_HPP