#include<iostream>
using namespace std ;

void pass(int a[]){
    cout<<a[0]<<endl;
    cout<<sizeof(a)<<endl;   // we see size(memory storage) of pointer dabba is getting print (8 bytes) ....par isse toh array ka size dena chahie tha ......so a is normal pointer dabba here
    a=a+1;  // pointer ki value change kr paare ...a normal pointer dabba hi h
   cout<<a<<endl;    //  address(base add) of array arr is getting print...so pointer a is storing base add of a
   cout<<&a<<endl;  // address of dabba a is getting print
   *a=*a+1;  // value of element at base add of array arr is getting increased by 1
  
}

// we observe array is passed by reference (arr pointer is passed -> address(base add) is passed  ) and is getting stored in pointer dabba .......int arr[] is acting as int*arr....... so we can use pointer only in function parameter to accept the value

void pass1(int* ptr){
    cout<<ptr[0]<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    *ptr=*ptr+1;
}



void fun1(int* ptr){
    cout<<ptr[0]<<endl;   // will print 2 
}


void fun2(int arr[]){
    cout<<arr[0]<<endl;   // will print 2  //int arr[] acts as int*arr
}



int main()
{
    int arr[]={1,2,3,4};
    cout<<sizeof(arr)<<endl; // arr is array ...size(memory storage) of array arr will be print (4*4=16 bytes)
    cout<<arr<<endl; // base add will be print
    cout<<&arr<<endl; // base add will be print
    cout<<*arr<<endl;  // element at base add will be print
    pass(arr);
     cout<<*arr<<endl;
    pass1(arr);
    cout<<*arr<<endl;

    // note: 
    fun1(arr+1);
    fun2(arr+1);


return 0;
}