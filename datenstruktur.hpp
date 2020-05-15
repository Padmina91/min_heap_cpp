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


#endif //MIN_HEAP_CPP_DATENSTRUKTUR_HPP