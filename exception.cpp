#include "exception.hpp"
using namespace std;

Exception::Exception(std::string error_code) {
    _error_code = error_code;
}

std::string Exception::to_string() {
    return _error_code;
}