#include "optional-lite/include/nonstd/optional.hpp"

#include <cstdlib>
#include <iostream>

using nonstd::optional;
using nonstd::nullopt;

optional<int> to_int(const char* const text) {
    char* pos = nullptr;
    const int value = strtol(text, &pos, 0);

    return pos == text ? nullopt : optional<int>(value);
}

int main(int argc, char* argv[]) {
    const char* text = argc > 1 ? argv[1] : "42";

    optional<int> oi = to_int(text);

    if (oi) 
        std::cout << text << " is " << *oi;
    else
        std::cout << text << " is " << "isn't a number";    

    return 0;
}