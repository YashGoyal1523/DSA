//  In C++, macros are preprocessor directives that allow you to define constants, functions, or code snippets that can be used throughout your code. They are typically defined using the #define directive and are evaluated by the preprocessor before the code is compiled.
//  Macros can be used for a variety of purposes, such as defining constants or creating shorthand for commonly used expressions.


#include<iostream>
using namespace std ;

#define pi 3.14

#define maxx(x,y) (x>y?x:y)


void area1(int r){
    cout<<3.14*r*r<<endl;
}

void area2(int r){
    cout<<pi*r*r<<endl;
}

void fun1(int a,int b){
    int c=a>b?a:b;
    cout<<c<<endl;
}

void fun2(int a,int b){
    int c=maxx(a,b);
    cout<<c<<endl;
}



int main()
{
    area1(3);
    area2(3);
    fun1(2,3);
    fun2(2,3);
return 0;
}