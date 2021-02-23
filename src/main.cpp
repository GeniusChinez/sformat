#include "sformat.h"
#include <iostream>

int main(int argc, char* const argv[]) {
    auto result = gc::format("%: something % % %%", 1, "else", "is", true, '?');
    std::cout << result << "\n";
    return 0;
}
