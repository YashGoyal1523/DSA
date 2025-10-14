#include<iostream>  //  new is an operator in C++ used for dynamic memory allocation.
using namespace std ;
int main()
{
    //static memory allocation- space allocated during compile time in stack memory
    int a;
    a=5;
    cout<<a<<endl;

    int b=5;
    cout<<b<<endl;

    // dynamic memory allocation - space allocated during runtime in heap memory
    int*c=new int; // or int*c=new int();   // int dabba created in heap memory with value zero(during runtime) and uska add stored in pointer dabba(pointer to int) named c (assigned during runtime)  which is created in stack memory(during compile time)
    *c=5; // int dabba ke value is 5
    cout<<*c<<endl;

    int *d=new int(4); // value 4 ka int dabba created 
    cout<<*d;

    int *e;
    e=new int;

    delete c; // heap memory freed  //heap wali clear hogyi ...stack wali bachi h abhi ie pointer c zinda h abhi (dangling pointer bangya) ....yeh baad m hi khatm hoga
    delete(d);
    delete(e);
return 0;
}


// static memory itswlf gets freed once code over...heap memory needs to be deleted


// dma

// Allocation:
// new allocates memory for a single object. new returns pointer to the allocated memory
// int* arr=new int(1);
// new[] allocates memory for an array of objects(ek bada single object allocate hojata which is capable of holding different chote objects). new[] returns pointer (pointer to single dabba) to the first element of the allocated array.
// int* arr=new int[5];
// Deallocation:
// delete must be used for memory allocated with new.
// delete[] must be used for memory allocated with new[].

// Using delete on new[] Allocation:
// This leads to undefined behavior because delete is not designed to handle memory that was allocated as an array. The runtime system may not correctly free the memory, which can result in:
// Memory leaks.
// Corruption of memory management data structures.
// Program crashes or unpredictable behavio

// Using delete[] with new:
// Undefined Behavior: If you use delete[] on a pointer that was allocated with new, the program will exhibit undefined behavior. This means the program may crash, corrupt memory, or produce unpredictable results.
// int* p = new int(10); // Allocate memory for a single integer
// delete[] p; // Incorrectly deallocate memory
// In this case, the runtime system expects p to point to an array of objects, so it may try to access additional metadata or array elements that don't exist. This can lead to various issues, such as:
// Memory Corruption: The runtime may modify or free memory regions that are not part of the allocated block.
// Crash: The program might crash if the runtime system tries to access or free invalid memory.
// Unpredictable Behavior: The program may behave inconsistently or incorrectly, depending on the specific implementation and the state of the memory.
