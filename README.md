### Cppstdint
A templated solution to using different width integral types

```C++
/*
 * The following program demonstrates sample usage of the Cppstdint library.
 * A pointer can be cast safely to an integral type as has been shown in the
 * main function without the need for a special uintptr_t type.  All integral
 * types in cstdint.h can technically be replaced with one universal class like
 * the following.  
 */
#include <iostream>
#include "Cppstdint.hpp"
using namespace std;
using namespace Cppstdint;

int main() {

    Int<sizeof(void*) * 8, UNSIGNED>::type int_handle = 
        (decltype(int_handle)) (void*)(0x444);
    cout << int_handle << endl;

    return 0;
}
```

