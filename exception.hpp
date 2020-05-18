#ifndef MIN_HEAP_CPP_EXCEPTION_HPP
#define MIN_HEAP_CPP_EXCEPTION_HPP
#include <exception>
#include <string>

class EmptyHeapException : public std::exception {};

class IndexOutOfBoundsException : public std::exception {};

#endif //MIN_HEAP_CPP_EXCEPTION_HPP