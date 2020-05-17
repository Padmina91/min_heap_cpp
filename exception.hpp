#ifndef MIN_HEAP_CPP_EXCEPTION_HPP
#define MIN_HEAP_CPP_EXCEPTION_HPP
#include <exception>
#include <string>

class EmptyHeapException : public std::exception {
public:
    explicit EmptyHeapException() = default;
};

class IndexOutOfBoundsException : public std::exception {
public:
    explicit IndexOutOfBoundsException() = default;
};

#endif //MIN_HEAP_CPP_EXCEPTION_HPP