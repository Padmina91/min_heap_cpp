#ifndef MIN_HEAP_CPP_EXCEPTION_HPP
#define MIN_HEAP_CPP_EXCEPTION_HPP

#include <string>

class Exception {
private:
    std::string _error_code;

public:
    explicit Exception(std::string error_code);
    std::string to_string();
};

#endif //MIN_HEAP_CPP_EXCEPTION_HPP