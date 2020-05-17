#ifndef MIN_HEAP_CPP_TESTTREIBER_HPP
#define MIN_HEAP_CPP_TESTTREIBER_HPP

#include "datenstruktur.hpp"
#include <iomanip>

class Testtreiber {
private:
// ---------- private Methoden Deklaration ----------
    template <typename T>
    bool test_min_heap_correctness(Heap<T>& heap_variable, int start_index, int heap_size);
    template <typename T>
    void test1(Heap<T>& heap_variable, const std::string& type_name);
    template <typename T>
    void test2(Heap<T>& heap_variable, const std::string& type_name);
    template <typename T>
    void test3(Heap<T>& heap_variable, const std::string& type_name);
    template <typename T>
    void test4(Heap<T>& heap_variable, const std::string& type_name);
    template <typename T>
    void test5(Heap<T>& heap_variable, const std::string& type_name);
    void test6(const std::string& type_name);
    template <typename T>
    void execute_all_tests(Heap<T>& heap_variable, const std::string& type_name);

public:
// ---------- public Methoden Definition ----------
    explicit Testtreiber() = default;
    ~Testtreiber() = default;

// ---------- public static Methoden Deklaration ----------
    static void execute_tests();
};

// ---------- private Methoden Implementierung ----------

/**
 * Durchläuft den Heap rekursiv und prüft, ob die Eigenschaft eines Min-Heaps erfüllt ist.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param start_index (int)
 * @param heap_size (int)
 * @return heap_correct (bool)
 */
template <typename T>
bool Testtreiber::test_min_heap_correctness(Heap<T>& heap_variable, int start_index, int heap_size) {
    bool heap_correct = true;
    int left_child_index = Heap<T>::index_of_left_child(start_index);
    bool left_child_exists = heap_size > left_child_index;
    int right_child_index = Heap<T>::index_of_right_child(start_index);
    bool right_child_exists = heap_size > right_child_index;
    int parent_index = Heap<T>::index_of_parent(start_index);
    bool parent_exists = true;
    if (parent_index == -1)
        parent_exists = false;
    if (left_child_exists)
        heap_correct = test_min_heap_correctness(heap_variable, left_child_index, heap_size);
    if (heap_correct && right_child_exists)
        heap_correct = test_min_heap_correctness(heap_variable, right_child_index, heap_size);
    try {
        if (heap_correct && parent_exists &&
            heap_variable.get_value_at(start_index) < heap_variable.get_value_at(parent_index)) {
            heap_correct = false;
        }
    } catch (IndexOutOfBoundsException&) {}
    return heap_correct;
}

/**
 * Testet, ob der Heap beim Aufrufen von .extract_min() und .minimum() wie erwartet
 * eine EmptyHeapException wirft.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::test1(Heap<T>& heap_variable, const std::string& type_name) {
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

/**
 * Testet, ob der Heap nach Einfügen von einigen immer kleiner werdenden Werten
 * korrekt sortiert wurde und die Eigenschaft eines Min-Heaps erfüllt.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::test2(Heap<T>& heap_variable, const std::string& type_name) {
    using namespace std;
    if ("int" == type_name) {
        for (int i = 100; i >= 0; i--)
            heap_variable.insert(i);
    }
    if ("float" == type_name || "double" == type_name) {
        float val = 100.0;
        for (int i = 0; i <= 200; i++, val -= 0.5)
            heap_variable.insert(val);
    }
    if ("char" == type_name) {
        char c = (char) 255;
        for (int i = 255; i >= 0; i--, c--)
            heap_variable.insert(c);
    }
    if (test_min_heap_correctness(heap_variable, 0, heap_variable.get_next()))
        cout << "Test 2 erfolgreich. (Datentyp: " << type_name << ")" << endl;
    else
        cout << "Test 2 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
}

/**
 * Testet, ob der Speicher vom Array _values erfolgreich verkleinert wird,
 * sobald die untersten zwei Reihen leer sind.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::test3(Heap<T>& heap_variable, const std::string& type_name) {
    using namespace std;
    int old_size = heap_variable.get_size();
    int decrease_at = old_size / 4 - 1;
    for (int i = heap_variable.get_next() - 1; i > decrease_at; i--) {
        heap_variable.extract_min();
    }
    if (heap_variable.get_size() == (old_size + 1) / 2 - 1)
        cout << "Test 3 erfolgreich. (Datentyp: " << type_name << ")" << endl;
    else
        cout << "Test 3 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
}

/**
 * Prüft, ob der Heap nach dem mehrmaligen Entfernen von Werten und nach dem
 * Verringern der Speicherkapazität noch korrekt sortiert ist.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::test4(Heap<T>& heap_variable, const std::string& type_name) {
    using namespace std;
    if (test_min_heap_correctness(heap_variable, 0, heap_variable.get_next()))
        cout << "Test 4 erfolgreich. (Datentyp: " << type_name << ")" << endl;
    else
        cout << "Test 4 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
}

/**
 * Testet, ob die Methode .minimum() wie erwartet das kleinste Element im Heap zurückgibt.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::test5(Heap<T>& heap_variable, const std::string& type_name) {
    using namespace std;
    T minimum = heap_variable.minimum();
    try {
        if (minimum == heap_variable.get_value_at(0))
            cout << "Test 5 erfolgreich. (Datentyp: " << type_name << ")" << endl;
        else
            cout << "Test 5 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
    } catch (IndexOutOfBoundsException&) {}
}

/**
 * Testet, ob der überladene Konstruktor funktioniert. Geprüft wird, ob der Heap
 * richtig sortiert wird und ob das Attribut _next den erwarteten Wert hat.
 * @param type_name (const string&)
 */
void Testtreiber::test6(const std::string& type_name) {
    using namespace std;
    const int arr_size = 51;
    if ("int" == type_name) {
        int arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = 100 - i;
        }
        Heap<int> heap2(arr);
        free(arr);
        if (test_min_heap_correctness(heap2, 0, heap2.get_next()) && heap2.get_next() == arr_size)
            cout << "Test 6 erfolgreich. (Datentyp: " << type_name << ")" << endl;
        else
            cout << "Test 6 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
    }
    if ("float" == type_name) {
        float arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = 150.53f - (float) i;
        }
        Heap<float> heap2(arr);
        
        if (test_min_heap_correctness(heap2, 0, heap2.get_next()) && heap2.get_next() == arr_size)
            cout << "Test 6 erfolgreich. (Datentyp: " << type_name << ")" << endl;
        else
            cout << "Test 6 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
    }
    if ("double" == type_name) {
        double arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = 200.87 - (double) i;
        }
        Heap<double> heap2(arr);
        
        if (test_min_heap_correctness(heap2, 0, heap2.get_next()) && heap2.get_next() == arr_size)
            cout << "Test 6 erfolgreich. (Datentyp: " << type_name << ")" << endl;
        else
            cout << "Test 6 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
    }
    if ("char" == type_name) {
        char arr[arr_size];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = (char) (150 - i);
        }
        Heap<char> heap2(arr);
        
        if (test_min_heap_correctness(heap2, 0, heap2.get_next()) && heap2.get_next() == arr_size)
            cout << "Test 6 erfolgreich. (Datentyp: " << type_name << ")" << endl;
        else
            cout << "Test 6 fehlgeschlagen. (Datentyp: " << type_name << ")" << endl;
    }
}

/**
 * Ruft alle Tests auf.
 * @tparam T (typename)
 * @param heap_variable (Heap<T>&)
 * @param type_name (const string&)
 */
template <typename T>
void Testtreiber::execute_all_tests(Heap<T>& heap_variable, const std::string& type_name) {
    test1(heap_variable, type_name);
    test2(heap_variable, type_name);
    test3(heap_variable, type_name);
    test4(heap_variable, type_name);
    test5(heap_variable, type_name);
    test6(type_name);
    std::cout << std::endl;
}

// ---------- public static Methoden Implementierung ----------

/**
 * Erstellt ein Objekt der Klasse Testtreiber, anhand von dem anschließend die
 * Klasse Heap mit vier verschiedenen Datentypen getestet wird (int, float, double, char).
 * Die künstlich erzeugten Scopes {} sind dazu da, um keinen Speicherplatz
 * zu verschwenden. Der Heap eines bestimmten Datentyps wird
 * zerstört, sobald der Scope verlassen wird.
 */
void Testtreiber::execute_tests() {
    Testtreiber testtreiber;
    
    {
        Heap<int> int_heap;
        testtreiber.execute_all_tests(int_heap, "int");
    }
    
    {
        Heap<float> float_heap;
        testtreiber.execute_all_tests(float_heap, "float");
    }
    
    {
        Heap<double> double_heap;
        testtreiber.execute_all_tests(double_heap, "double");
    }
    
    {
        Heap<char> char_heap;
        testtreiber.execute_all_tests(char_heap, "char");
    }
}

#endif //MIN_HEAP_CPP_TESTTREIBER_HPP