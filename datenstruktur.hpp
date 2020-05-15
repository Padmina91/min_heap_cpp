#ifndef MIN_HEAP_CPP_DATENSTRUKTUR_HPP
#define MIN_HEAP_CPP_DATENSTRUKTUR_HPP

#include <string>

template<typename T>
class Heap {
private:
// ---------- private Attribute ----------
    int _size;
    int _next;
    T *_values;

// ---------- private Methoden ----------
    void increase_capacity();
    void decrease_capacity();
    void assert_min_heap_bottom_up(int start_index);

// ----------- private static Methoden ----------
    static int index_of_parent(int child_index);
    static int index_of_left_child(int parent_index);
    static int index_of_right_child(int parent_index);

public:
// ---------- public Methoden ----------
    explicit Heap(int size);
    ~Heap();
    void insert(int val);
    /*T minimum();
    void extract_min();
    std::string to_string();*/
};


#include "exception.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// ---------- private Methoden ----------

template <typename T>
void Heap<T>::increase_capacity() {
    int i = 0;
    int old_size = _size;
    while ( (int) pow(2, i) <= _size) {
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
        _size = (int) pow(2, i-2) * 2 - 1;

        T *temp = new T[_size];
        for (int j = 0; j < _size; j++)
            temp[j] = _values[j];
        delete[] _values;
        _values = temp;
    }
}

template <typename T>
void Heap<T>::assert_min_heap_bottom_up(int start_index) {
    int parent_index;
    bool parent_exists = true;
    try {
        parent_index = index_of_parent(start_index);
    } catch (char* e) {
        parent_exists = false;
        cout << e << endl;
    }
    cout << "Ich stehe nach dem catch Block." << endl;

    /*int left_child_index = index_of_left_child(start_index);
    int right_child_index = index_of_right_child(start_index);
    bool parent_exists;
    if (parent_index == -1) {
        parent_exists = false;
    } else {
        parent_exists = true;
    }
    bool left_child_exists = h->next > left_child_index;
    bool right_child_exists = h->next > right_child_index;
    if (left_child_exists) {
        assert_min_heap_bottom_up(h, left_child_index);
    }
    if (right_child_exists) {
        assert_min_heap_bottom_up(h, right_child_index);
    }
    if (parent_exists && h->values[start_index] < h->values[parent_index]) {
        int temp = h->values[start_index];
        h->values[start_index] = h->values[parent_index];
        h->values[parent_index] = temp;
    }*/
}

// ---------- private static Methoden ----------

template <typename T>
int Heap<T>::index_of_parent(int child_index) {
    if (child_index != 0) {
        return (child_index - 1) / 2;
    } else {
        throw Exception("no parent exception!!");
    }
}

template <typename T>
int Heap<T>::index_of_left_child(int parent_index) {
    return parent_index * 2 + 1;
}

template <typename T>
int Heap<T>::index_of_right_child(int parent_index) {
    return parent_index * 2 + 2;
}

// ---------- public Methoden ----------

template <typename T>
Heap<T>::Heap(int size) {
    _size = 1;
    _next = 0;
    _values = new T[_size];
}

template <typename T>
Heap<T>::~Heap() {
    delete[] _values;
}

template <typename T>
void Heap<T>::insert(int val) {
    if (_size == _next) {
        increase_capacity();
    }
    _values[_next] = val;
    _next++;
    assert_min_heap_bottom_up(0);
}




#endif //MIN_HEAP_CPP_DATENSTRUKTUR_HPP