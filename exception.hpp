#ifndef MIN_HEAP_CPP_EXCEPTION_HPP
#define MIN_HEAP_CPP_EXCEPTION_HPP

#include <string>

class EmptyHeapException {
private:
    std::string _error_code;

public:
    explicit EmptyHeapException();
    std::string to_string();
};

#endif //MIN_HEAP_CPP_EXCEPTION_HPP