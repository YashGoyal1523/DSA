// const keyword

#include<iostream>
using namespace std ;
int main()
{

    const int x=10; // int const x =10;  yeh bhi likh skte // x ki value 10 fix ......ab dobara change nhi kr skte and koshish krege toh compilation error aayega
    // x=2; // this is wrong
    cout<<x<<endl;
   

   // const with pointers
   // 1.CONST data,NON CONST pointer  (* se phle const)
    int a=10;
    const int*ptr=&a; //int const *ptr=&a;  //  pointer ko reassign kr skte , pointer ke andar stored address ka data modify nhi kr skte
    // *ptr=2 // this is wrong
    int b=2;
    ptr=&b; // yeh kr skte
    cout<<*ptr<<endl;
   // *ptr=3; // yeh nhi kr skte

// 2. NON CONST data, CONST pointer (* ke baad const)
    int *const p=&a; // pointer ko reassign nhi kr skte , pointer ke andar stored address ka data modify  kr skte
    *p=3; // kr skte
    cout<<*p<<endl;
   //p=&b; // yeh nhi kr skte

   //3.CONST data,CONST pointer (* ke phle baad dono jagah const)
    const int * const pt=&a; // // pointer ko reassign nhi kr skte , pointer ke andar stored address ka data modify nhi kr skte
   // *pt=4; // nhi kr skte
   // pt=&b; // nhi kr skte
return 0;
}



// note
// Constant Member Functions:

// In classes, member functions can be declared as const to indicate that they do not modify the object.

// class MyClass {
// public:
//     int getValue() const {
//         return value;
//     }

// private:
//     int value;
// };