#include<iostream>
using namespace std ;

void pass(int*p){                  // int*&p krdege toh by reference hojayega......nickname wala system
    p=p+1;
}


int main()
{
    int a=5;
    int *p=&a;

    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;

    pass(p);    // passed by value

    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;



return 0;
}