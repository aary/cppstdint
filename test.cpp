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
