// A Cast operator is a unary operator which forces one data type to be converted into another data type.

// C++ supports 4 types of casting:

// Static Cast
// Dynamic Cast
// Const Cast
// Reinterpret Cast

// This is the simplest type of cast that can be used. It is a compile-time cast. It does things like implicit conversions between types (such as int to float etc, or pointer to void* or etc), and it can also call explicit conversion functions.

//syntax
// static_cast <dest_type> (source);
//The return value of static_cast will be of dest_type.


#include <iostream>
using namespace std;
 

int main()
{
    float f = 3.5;
 
    // Implicit type case
    // float to int
    int a = f;
    cout << "The Value of a: " << a;
 
    // using static_cast for float to int
    int b = static_cast<int>(f);
    cout << "\nThe Value of b: " << b;
}