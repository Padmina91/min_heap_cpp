#ifndef MIN_HEAP_CPP_TESTTREIBER_HPP
#define MIN_HEAP_CPP_TESTTREIBER_HPP

#include "datenstruktur.hpp"
#include <string>

class Testtreiber {
private:
// ---------- private Methoden Deklaration ----------
    template <typename T>
    void test1(Heap<T> heap_variable, const std::string& type_name);
    template <typename T>
    void test2(Heap<T> heap_variable, const std::string& type_name);
    template <typename T>
    void test3(Heap<T> heap_variable, const std::string& type_name);
    template <typename T>
    void test4(Heap<T> heap_variable, const std::string& type_name);
    template <typename T>
    void test5(Heap<T> heap_variable, const std::string& type_name);

public:
// ---------- public Methoden Deklaration ----------
    explicit Testtreiber() = default;
    ~Testtreiber() = default;
    
// ---------- public static Methoden Deklaration ----------
    static void execute_tests();
};

// ---------- private Methoden Implementierung ----------

template <typename T>
void Testtreiber::test1(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    cout << "Test 1 wird ausgef\x81hrt mit Datentyp " << type_name << endl;
}

template <typename T>
void Testtreiber::test2(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    cout << "Test 2 wird ausgef\x81hrt mit Datentyp " << type_name << endl;
}

template <typename T>
void Testtreiber::test3(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    cout << "Test 3 wird ausgef\x81hrt mit Datentyp " << type_name << endl;
}

template <typename T>
void Testtreiber::test4(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    cout << "Test 4 wird ausgef\x81hrt mit Datentyp " << type_name << endl;
}

template <typename T>
void Testtreiber::test5(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    cout << "Test 5 wird ausgef\x81hrt mit Datentyp " << type_name << endl;
}

// ---------- public Methoden Implementierung ----------

void Testtreiber::execute_tests() {
    Heap<int> int_heap;
    Testtreiber testtreiber;
    testtreiber.test1(int_heap, "int");
    testtreiber.test2(int_heap, "int");
    testtreiber.test3(int_heap, "int");
    testtreiber.test4(int_heap, "int");
    testtreiber.test5(int_heap, "int");
    int_heap.~Heap();
    
    std::cout << std::endl;
    
    Heap<float> float_heap;
    testtreiber.test1(float_heap, "float");
    testtreiber.test2(float_heap, "float");
    testtreiber.test3(float_heap, "float");
    testtreiber.test4(float_heap, "float");
    testtreiber.test5(float_heap, "float");
    testtreiber.~Testtreiber();
    float_heap.~Heap();
    
    std::cout << std::endl;
    
    Heap<double> double_heap;
    testtreiber.test1(double_heap, "double");
    testtreiber.test2(double_heap, "double");
    testtreiber.test3(double_heap, "double");
    testtreiber.test4(double_heap, "double");
    testtreiber.test5(double_heap, "double");
    testtreiber.~Testtreiber();
    double_heap.~Heap();
    
    std::cout << std::endl;
    
    
    
    /*heap_variable.test1(heap_variable); Warum wirft das hier keinen Fehler??
    heap_variable.test2(heap_variable);
    heap_variable.test3(heap_variable);
    heap_variable.test4(heap_variable);
    heap_variable.test5(heap_variable);
    heap_variable.~Testtreiber();*/
}

#endif //MIN_HEAP_CPP_TESTTREIBER_HPP