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
    template <typename T>
    void execute_all_tests(Heap<T> heap_variable, const std::string& type_name);

public:
// ---------- public Methoden Definition ----------
    explicit Testtreiber() = default;
    ~Testtreiber() = default;
    
// ---------- public static Methoden Deklaration ----------
    static void execute_tests();
};

// ---------- private Methoden Implementierung ----------

template <typename T>
void Testtreiber::test1(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    bool catch_activated = false;
    try {
        heap_variable.extract_min();
    } catch (EmptyHeapException&) {
        catch_activated = true;
    }
    if (catch_activated) {
        try {
            heap_variable.minimum();
        } catch (EmptyHeapException&) {
            cout << "Test 1 erfolgreich. (Datentyp: " << type_name << ")" << endl;
            return;
        }
    }
    cout << "Test 1 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
}

template <typename T>
void Testtreiber::test2(Heap<T> heap_variable, const std::string& type_name) {
    using namespace std;
    
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

template <typename T>
void Testtreiber::execute_all_tests(Heap<T> heap_variable, const std::string& type_name) {
    test1(heap_variable, type_name);
    test2(heap_variable, type_name);
    test3(heap_variable, type_name);
    test4(heap_variable, type_name);
    test5(heap_variable, type_name);
    std::cout << std::endl;
}

// ---------- public static Methoden Implementierung ----------

void Testtreiber::execute_tests() {
    Testtreiber testtreiber;
    
    Heap<int> int_heap;
    testtreiber.execute_all_tests(int_heap, "int");
    
    Heap<float> float_heap;
    testtreiber.execute_all_tests(float_heap, "float");
    
    Heap<double> double_heap;
    testtreiber.execute_all_tests(double_heap, "double");

    Heap<char> char_heap;
    testtreiber.execute_all_tests(char_heap, "char");
}

#endif //MIN_HEAP_CPP_TESTTREIBER_HPP