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

template <typename T>
bool Heap<T>::is_empty() {
    return _next <= 0;
}

// ----------- private static Methoden Implementierung ----------

template <typename T>
int Heap<T>::index_of_parent(int child_index) {
    if (child_index != 0) {
        return (child_index - 1) / 2;
    }
    return -1;
}

template <typename T>
int Heap<T>::index_of_left_child(int parent_index) {
    return parent_index * 2 + 1;
}

template <typename T>
int Heap<T>::index_of_right_child(int parent_index) {
    return parent_index * 2 + 2;
}

// ---------- public Methoden Implementierung ----------

template <typename T>
Heap<T>::Heap() {
    _size = 15;
    _next = 0;
    _values = new T[_size];
}

template <typename T>
Heap<T>::~Heap() {
    delete[] _values;
}

template <typename T>
int Heap<T>::get_size() {
    return _size;
}

template <typename T>
int Heap<T>::get_next() {
    return _next;
}

template <typename T>
T Heap<T>::get_value_at(int index) {
    return _values[index];
}

template <typename T>
void Heap<T>::insert(T val) {
    if (_size == _next) {
        increase_capacity();
    }
    _values[_next] = val;
    _next++;
    assert_min_heap_bottom_up(0);
}

template <typename T>
T Heap<T>::minimum() {
    if (is_empty()) {
        throw EmptyHeapException();
    } else {
        return _values[0]; // da es sich um einen Min-Heap handelt, steht das kleinste Element immer an erster Stelle
    }
}

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