#include <iostream>

int main() {
    int var = 42;       // Declare an integer variable
    int *ptr = &var;    // Declare a pointer and assign it the address of var

    // Output the value of var
    std::cout << "Value of var: " << var << std::endl;

    // Output the address of var
    std::cout << "Address of var: " << &var << std::endl;

    // Output the value stored in the pointer (which is the address of var)
    std::cout << "Value stored in ptr (address of var): " << ptr << std::endl;

    // Output the value pointed to by the pointer (which is the value of var)
    std::cout << "Value pointed to by ptr: " << *ptr << std::endl;

    return 0;
}