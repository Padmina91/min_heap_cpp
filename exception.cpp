#include "exception.hpp"

EmptyHeapException::EmptyHeapException() {
    _error_code = "Error! Heap is empty!";
}

std::string EmptyHeapException::to_string() {
    return _error_code;
}