#include<iostream>
#include<typeinfo> // for typeid()
using namespace std ;
int main()
{
    int a ;

    decltype(a) b; // it will declare b as same datatype as that of a

    cout<<typeid(b).name();  // returns the datatype of variable b      

return 0;
}


//note:  if there was a function func()...  decltype(func()) b ; it will assign b with return type of func()


//note:

// typeid is an operator that is used where the dynamic type of an object needs to be known. 

// typeid(x).name() returns the data type of x, for example, it returns:

// ‘i’ for integers, ‘d’ for doubles,
// ‘f’ for float, ‘c’ for char, 
// Pi’ for the pointer to the integer,
// ‘Pd’ for the pointer to double,’
// Pf’ for the pointer to float, 
// ‘Pc’ for the pointer to char,
// ‘PPi’ for the pointer to pointer to integer.
// Single Pointer results in  prefix ‘P’,
// double-pointer results in ‘PP’ as a prefix and so on.