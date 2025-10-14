// Unary operators are the operators that perform operations on a single operand to produce a new value.

// Types of unary operators are mentioned below:
// Unary minus ( - )
// Increment ( ++ )
// Decrement ( -- )
// NOT ( ! )
// Addressof operator ( & )
// sizeof()
// dereference operator ( * )

// The minus operator ( – ) changes the sign of its argument. A positive number becomes negative, and a negative number becomes positive.
// The logical NOT operator ( ! ) is used to reverse the logical state of its operand. If a condition is true, then the Logical NOT operator will make it false.
// The addressof operator ( & ) gives an address of a variable. It is used to return the memory address of a variable. These addresses returned by the address-of operator are known as pointers because they “point” to the variable in memory.

// The sizeof operator is a unary compile-time operator used to determine the size of variables, data types, and constants in bytes at compile time. It can also determine the size of classes, structures, and unions.

//The * operator is used to access the value stored at a particular memory address.// *(address) gives value stored at dabba jo is address par hai  if ptr is a pointer to some variable, *ptr gives you the value of that variable.

#include<iostream>
using namespace std ;
int main()
{
    //int -> 4 byte
	int num = 50;
	cout << sizeof(num) << endl;

     int c=10;
     int d=10;
    cout<<(c++)*(++c)<<endl;
    cout<<(++d)*(d++)<<endl;

    int a=10;
    cout<<&a<<endl;  //&_ gives address of dabba _ // address of dabba _ is address of its first byte // &_ gives address of first byte of dabba _    //  gives address of dabba a 
    
    cout<<&a+1<<endl; // gives address of byte just after skipping bytes  jitni 'a' dabbe  mein h once from first byte of dabba'a' (including it) ie skipping ek dabba of size that of 'a' dabba from first byte of dabba (included in skippingdabba) and dabba khatm hote hi phli byte ka address 
    cout<<&a+2<<endl; // gives address of byte just after skipping bytes  jitni are in 'a' twice(including initial) ie skipping two dabbas of size that of 'a dabba' and khatm hote hi phli byte
	

    cout<<*(&a)<<endl;   //*(&_) gives value gives stored at dabba _ //gives value of  dabba 'a'     // note : trick:  *(&_) socho isme * and & ek dusre ko nullify krdere and hamare paas sirf _ bachgyaaa .... toh ese socho sirf _ likha hai 
return 0;
}