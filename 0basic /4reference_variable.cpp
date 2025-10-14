#include<iostream>         // concept in  c++ not in c
using namespace std ;
int main()
{
    int a=5; // normal integer variable a
    int& b=a; // b is a reference variable refering to a....b is nickname/alias for variable a .....isme koi alag dabba nhi banta bas nickname bantaa
    int&c=a; // c is a reference variable refering to a....c is nickname/alias for variable a
    int &d=a; // d is a reference variable refering to a....d is nickname/alias for variable a
    int& n=n; // ese bhi likh skte.....n hi nickname n ka



    cout<<a<<endl<<b<<endl<<c<<endl;

    b++;

   cout<<a<<endl<<b<<endl<<c<<endl;

   // note:
   int x=10;
   int *ptr=&x;
   int z=*ptr; //  *ptr evaluates to x -> int z=x . so value of z becomes equal to that of x ie 10
   int &y=*ptr; //  *ptr evaluates to x ->int &y=x . So y becomes an alias for x.
   

return 0;
}


// constant cant be stored in reference variable;

// note same ese hi tariko se pointer dabba banta bas star use hota   int* x=&a , int*x=&a , int *x=&a .....

// vector,string m bhi kr sktee...array mein noi