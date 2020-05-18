//
// Created by Mina on 15.05.2020.
//

#ifndef MIN_HEAP_CPP_DATENSTRUKTUR_HPP
#define MIN_HEAP_CPP_DATENSTRUKTUR_HPP

#include "exception.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

template <typename T>
class Heap {
private:
// ---------- private Attribute ----------
    int _size;
    int _next;
    T *_values;

// ---------- private Methoden Deklaration ----------
    void increase_capacity();
    
    void decrease_capacity();
    
    void assert_min_heap_bottom_up(int start_index);
    
    void assert_min_heap_top_down(int start_index);
    
    bool is_empty();

public:
// ----------- public static Methoden Deklaration ----------
    static int index_of_parent(int child_index);
    
    static int index_of_left_child(int parent_index);
    
    static int index_of_right_child(int parent_index);

// ---------- public Methoden Deklaration ----------
    explicit Heap();
    
    template <size_t N>
    explicit Heap(T (& arr)[N]);
    
    ~Heap();
    
    int get_size();
    
    int get_next();
    
    T get_value_at(int index);
    
    void insert(T val);
    
    T minimum();
    
    void extract_min();
    
    std::string to_string();
};

// ---------- private Methoden Implementierung ----------

/**
 * Fügt dem Heap eine weitere Ebene hinzu.
 * @tparam T (typename)
 */
template <typename T>
void Heap<T>::increase_capacity() {
    int i = 0;
    int old_size = _size;
    while ((int) pow(2, i) <= _size) {
        i++;
    }
    _size = (int) pow(2, i) * 2 - 1;
    T *temp = new T[_size];
    for (int j = 0; j < old_size; j++)
        temp[j] = _values[j];
    delete[] _values;
    _values = temp;
}

/**
 * Löscht die unterste Ebene des Heaps.
 * @tparam T (typename)
 */
template <typename T>
void Heap<T>::decrease_capacity() {
    int i = 0;
    while (pow(2, i) < _size)
        i++;
    
    if (i > 0) {
        _size = (int) pow(2, i - 2) * 2 - 1;
        
        T *temp = new T[_size];
        for (int j = 0; j < _size; j++)
            temp[j] = _values[j];
        delete[] _values;
        _values = temp;
    }
}

/**
 * Durchläuft den Heap rekursiv und reicht bei Änderungsbedarf einen Wert von unten
 * nach oben durch den Heap, solange bis die Min-Heap-Eigenschaft wiederhergestellt ist.
 * @tparam T (typename)
 * @param start_index (int)
 */
template <typename T>
void Heap<T>::assert_min_heap_bottom_up(int start_index) {
    int left_child_index = index_of_left_child(start_index);
    bool left_child_exists = _next > left_child_index;
    int right_child_index = index_of_right_child(start_index);
    bool right_child_exists = _next > right_child_index;
    int parent_index = index_of_parent(start_index);
    bool parent_exists = true;
    if (parent_index == -1) {
        parent_exists = false;
    }
    if (left_child_exists) {
        assert_min_heap_bottom_up(left_child_index);
    }
    if (right_child_exists) {
        assert_min_heap_bottom_up(right_child_index);
    }
    if (parent_exists && _values[start_index] < _values[parent_index]) {
        T temp = _values[start_index];
        _values[start_index] = _values[parent_index];
        _values[parent_index] = temp;
    }
}

/**
 * Durchläuft den Heap rekursiv und reicht bei Änderungsbedarf einen Wert von oben
 * nach unten durch den Heap, solange bis die Min-Heap-Eigenschaft wiederhergestellt ist.
 * @tparam T (typename)
 * @param start_index (int)
 */
template <typename T>
void Heap<T>::assert_min_heap_top_down(int start_index) {
    int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool left_child_exists = _next > left_child_index;
    bool right_child_exists = _next > right_child_index;
    if (left_child_exists && right_child_exists) {
        if (_values[left_child_index] < _values[right_child_index]) {
            if (_values[left_child_index] < _values[start_index]) {
                int temp = _values[start_index];
                _values[start_index] = _values[left_child_index];
                _values[left_child_index] = temp;
                assert_min_heap_top_down(left_child_index);
            }
        } else {
            if (_values[right_child_index] < _values[start_index]) {
                int temp = _values[start_index];
                _values[start_index] = _values[right_child_index];
                _values[right_child_index] = temp;
                assert_min_heap_top_down(right_child_index);
            }
        }
    } else if (left_child_exists && _values[left_child_index] < _values[start_index]) {
        int temp = _values[start_index];
        _values[start_index] = _values[left_child_index];
        _values[left_child_index] = temp;
    }
}

/**
 * Gibt an, ob der Heap leer ist. true = Heap leer. false = Heap hat mind. 1 Element
 * @tparam T (typename)
 * @return is_empty (bool)
 */
template <typename T>
bool Heap<T>::is_empty() {
    return _next <= 0;
}

// ----------- private static Methoden Implementierung ----------

/**
 * Gibt den Eltern-Index zurück oder -1, falls es keinen Eltern-Knoten gibt.
 * @tparam T (typename)
 * @param child_index (int)
 * @return index_of_parent (int)
 */
template <typename T>
int Heap<T>::index_of_parent(int child_index) {
    if (child_index != 0) {
        return (child_index - 1) / 2;
    }
    return -1;
}

/**
 * Gibt den Index des linken Kind-Knotens zurück.
 * @tparam T (typename)
 * @param parent_index (int)
 * @return index_of_left_child
 */
template <typename T>
int Heap<T>::index_of_left_child(int parent_index) {
    return parent_index * 2 + 1;
}

/**
 * Gibt den Index des rechten Kind-Knotens zurück.
 * @tparam T (typename)
 * @param parent_index (int)
 * @return index_of_right_child
 */
template <typename T>
int Heap<T>::index_of_right_child(int parent_index) {
    return parent_index * 2 + 2;
}

// ---------- public Methoden Implementierung ----------

/**
 * Standard-Konstruktor des Heaps. Es wird ein leerer Heap mit 3 Ebenen (also 15 Speicherplätzen) erstellt.
 * @tparam T (typename)
 */
template <typename T>
Heap<T>::Heap() {
    _size = 15;
    _next = 0;
    _values = new T[_size];
}

/**
 * Überladener Konstruktor: Befüllt das Array T* _values
 * mit den Werten im übergebenen Array arr.
 * @tparam T (typename)
 * @tparam N (size_t)
 * @param &arr (T*)
 */
template <typename T>
template <size_t N>
Heap<T>::Heap(T (& arr)[N]) {
    int size_of_arr = N;
    int exponent = 0;
    while (size_of_arr / (int) pow(2, exponent) >= 1) {
        exponent++;
    }
    _size = (int) pow(2, exponent) * 2 - 1; // mind. 1 komplett freie Ebene
    _next = 0;
    _values = new T[_size];
    for (int i = 0; i < size_of_arr; i++) {
        insert(arr[i]);
    }
}

/**
 * Destruktor des Heaps. Der Speicherbereich des Arrays T* _values wird freigegeben.
 * @tparam T (typename)
 */
template <typename T>
Heap<T>::~Heap() {
    delete[] _values;
    _values = nullptr;
}

/**
 * Gibt die aktuelle Größe des Heaps zurück.
 * @tparam T (typename)
 * @return _size (int)
 */
template <typename T>
int Heap<T>::get_size() {
    return _size;
}

/**
 * Gibt den aktuellen Wert des Attributs _next zurück.
 * @tparam T (typename)
 * @return _next (int)
 */
template <typename T>
int Heap<T>::get_next() {
    return _next;
}

/**
 * Gibt den Wert an der Stelle index zurück. Falls ein ungültiger Wert
 * für index übergeben wird, wird eine IndexOutOfBoundsException geworfen.
 * @throws IndexOutOfBoundsException
 * @tparam T (typename)
 * @param index (int)
 * @return _values[index] (T)
 */
template <typename T>
T Heap<T>::get_value_at(int index) {
    if (index >= _next || index < 0)
        throw IndexOutOfBoundsException();
    else
        return _values[index];
}

/**
 * Fügt den Wert val in den Heap ein und sortiert anschließend den Heap neu.
 * @tparam T (typename)
 * @param val (T)
 */
template <typename T>
void Heap<T>::insert(T val) {
    if (_size == _next) {
        increase_capacity();
    }
    _values[_next] = val;
    _next++;
    assert_min_heap_bottom_up(0);
}

/**
 * Gibt das kleinste Element des Heaps zurück. Ist kein Element vorhanden,
 * wird eine EmptyHeapException geworfen.
 * @throws EmptyHeapException
 * @tparam T (typename)
 * @return _values[0] (T)
 */
template <typename T>
T Heap<T>::minimum() {
    if (is_empty()) {
        throw EmptyHeapException();
    } else {
        return _values[0]; // da es sich um einen Min-Heap handelt, steht das kleinste Element immer an erster Stelle
    }
}

/**
 * Entfernt das kleinste Element aus dem Heap. Ist der Heap leer,
 * wird eine EmptyHeapException geworfen.
 * @throws EmptyHeapException
 * @tparam T (typename)
 */
template <typename T>
void Heap<T>::extract_min() {
    if (!is_empty()) {
        _values[0] = _values[_next - 1];
        _next--;
        if (!is_empty()) {
            assert_min_heap_top_down(0);
        }
        if ((_next + 1) * 4 == _size + 1) {
            decrease_capacity();
        }
    } else {
        throw EmptyHeapException();
    }
}

/**
 * Wandelt den Inhalt des Heaps in einen String um und gibt diesen zurück.
 * @tparam T (typename)
 * @return heap_string (string)
 */
template <typename T>
std::string Heap<T>::to_string() {
    using namespace std;
    ostringstream heap_string(std::ostringstream::ate);
    if (!is_empty()) {
        heap_string << _values[0];
        if (_next > 1) {
            for (int i = 1; i < _next; i++) {
                heap_string << ", ";
                heap_string << _values[i];
            }
        }
    }
    return heap_string.str();
}

#endif //MIN_HEAP_CPP_DATENSTRUKTUR_HPP