
// static polymorphism or compile time polymorphism 

// eg1 function overloading
 // function ka return type and parameters badal do toh same naam se chaljayege alag alag 



#include<iostream>
using namespace std ;


int add(int a,int b)
{
    return a+b;
}

double add(double a,double b)
{
    return a+b;
}



int add(int a,int b,int c)
{
    return a+b+c;
}



int main()
{
    cout<<add(1,2)<<endl;
    cout<<add(1.2,2.2)<<endl;
    cout<<add(1,2,3)<<endl;
return 0;                            
}


// eg : parametrised ctor