// The auto keyword in C++ specifies that the type of the variable that is being declared will be automatically deducted from its initializer. the auto keyword can also be used to declare the return type of a function. In the case of functions, if their return type is auto then that will be evaluated by return type expression at runtime. Good use of auto is to avoid long initializations when creating iterators for containers.   

// Note: The variable declared with auto keyword should be initialized at the time of its declaration only or else there will be a compile-time error.





#include<iostream>
using namespace std ;
int main()
{
    // auto a; 
    // a=1;   will give error

    auto a=1;
return 0;
}