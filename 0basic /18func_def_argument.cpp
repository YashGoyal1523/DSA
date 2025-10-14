//n C++, default arguments allow you to specify a default value for a function parameter. If the caller does not provide a value for that parameter, the default value will be used


#include<iostream>
using namespace std ;

void fun1(int a,int b,int z=2,int y=3){  // z,y wali is default argument  
    cout<<a+b+z+y<<endl;
}

void fun2(int a,int b,int z=2,int y=3){  // z,y wali is default argument
    cout<<a+b+z+y<<endl;
}

//                               default argument ke liye call krte hue value pass kar bhi skte nhi bhi kar skte.....agar value nhi pass ki toh jo assign ki voh hi rhegi iski value and pass krdi toh jo di h voh hojayegi value
//  note: default arguments rightmost mein hi likh skte ...ese hi khi bhi bich m nhi likh skte

int main()
{
    fun1(2,3);
    fun2(2,3,4);
return 0;
}