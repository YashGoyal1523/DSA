#include<iostream>             // new keyword is used for dma
using namespace std ;
int main()
{
// static mem allocation of array   // space is determined during compile time ....alloacted in stack memory
// int arr[5]={1,2,3,4,5}; 

// dynamic mem allocation of array      // space is determined during run time ....allocated in heap memory
//int* arr=new int[5];    // arr naam ka pointer dabba(pointer to int) created in stack memory(during compile time) and array of size 5 created in heap memory(during runtime) and pointer is pointing to address of first element of array (assigned during runtime)

// note:
// int n;
// cout<<"enter no of elements";
// cin>>n; 
// int arr[n];  this is bad practice....as stack m limited memory hoti choti si and agar n bada nikalgya toh dikkat hojayegi baad mein..also maybe some compilers mein na chala

// toh agar variable size ka array banana h toh better rhega dma kro
//int* arr=new int[n];  



int n;
cout<<"enter no of elements";
cin>>n; 
int* arr=new int[n];


//functioning ke liye normal socho arr naam ka hi array banaya h

//taking inputs      // arr[index]      
cout<<"enter elements ";
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}

// printing array 
cout<<"array is";
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}


//note:
arr=arr+1;  // normal pointer hi h toh kr skte


//memory free
delete[] arr;


return 0;
}

//  agar array func mein paas krna h toh arr hi paas karlege


// // note:
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
