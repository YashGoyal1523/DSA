// #include <bits/stdc++.h>  //  c++ standard library : yeh include krli toh aur kuch krne ki zrurat noi
#include <iostream>     
using namespace std; // iostream mein ek keyword ki many definitions available written in different namespaces (ez language mein blocks )
int main()
{

    // print
    cout << "hello";

    cout << endl; // next line

    cout << '\n';

    cout << "\nhi\n"  << endl<< "hi" << '\n' << "hi";

// datatypes
    int x = 20;
    cout << '\n';
    cout << x;
    cout << endl;
    cout << sizeof(x);

    cout << endl;

    char ch = 'a';

    cout << ch << endl;

    bool bo=true;
    bool boo=1;  // true  // non-zero integers are considered true and zero is considered false in boolean extract
    bool booo=0;  // false
    bool boooo=4; // true
    

    cout<<bo<<endl;  // cout->true->1
    cout<<boo<<endl; // cout->true->1
    cout<<booo<<endl; // cout->false->1
    cout<<boooo<<endl; //cout->true-> 1

// operators

// arithematic
    int a = 50;
    int b = 50;
    int c = a + b;

    cout << "sum is :" <<a + b << endl << c ;

    cout << endl;

    // relational

    cout<<(a>b);     //true-1 false-0 
cout << endl;
cout<<(a<=b);

cout << endl;

// input
int d;
cin>>d;
cout<<d;

cout << endl;

char chh;

cin>>chh;

cout<<chh;


    return 0;
}




// boilerplate is cp