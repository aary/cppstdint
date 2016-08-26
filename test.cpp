/*
 * The following program demonstrates sample usage of the Cppstdint library.
 * A pointer can be cast safely to an integral type as has been shown in the
 * main function without the need for a special uintptr_t type.  All integral
 * types in <cstdint> can technically be replaced with one universal class like
 * the following.
 */
#include <iostream>
#include <limits>
#include <cassert>
#include "Cppstdint.hpp"
using namespace std;
using namespace Cppstdint;

int main() {

    // demonstration of a pointer handle
    Int<sizeof(void*) * 8, SignType::UNSIGNED>::type int_handle =
        (decltype(int_handle)) (void*)(0x444);
    assert(int_handle == 1092);

    // demonstration of printing the maximum primitive int value
    Int<MAX, SignType::UNSIGNED>::type maximum_primitive_int =
        std::numeric_limits<decltype(maximum_primitive_int)>::max();
    auto max_number =
        std::numeric_limits<decltype(maximum_primitive_int)>::max();
    assert(maximum_primitive_int == max_number);
    assert(false);

    return 0;
}
