#include<iostream>               
using namespace std ; //A pointer in C and C++ is a variable that stores the memory address of another variable.  // pointer is a dabba that stores address of other dabba
int main()
{
    int a=1;

    // intialising,declaring pointer

    // int *ptr; // pointer dabba created which will store add of int dabba   // pointer to int // integer pointer // pointer to single dabba
    // ptr=&a;

    
  cout<<sizeof(ptr)<<endl<<endl;  


    // dereferencing : getting access to memory (dabba) to which pointer points :   *(pointer)
    
     // int*ptr= &a;  //  *ptr evaluates to a  // trick : *ptr = *(&a) {* and & cancels} = a 

    // cout<< *ptr = cout<< a // value of a gets print

    

    cout<<ptr<<endl<<*ptr<<endl<<&ptr<<endl<<endl;      //*ptr will give value stored at address which ptr points  // &ptr will give address of ptr dabba
    

    cout<<*ptr<<endl<<*ptr+1<<endl<<*(ptr)+1<<endl<<(*ptr)+1<<endl<<(*ptr)++<<endl<<++(*ptr)<<endl<<endl;


    // null pointer
    int*ptr0=0;         // null ptr ptr0 created
    int*ptr1=nullptr;

    cout<<ptr1<<endl<<endl;   // stores zero address  
      // accessing *ptr1 ie value of null pointer will give error
  
    // copying pointer
    int*ptrr=ptr;   // pointer  dabba ptrr created storing value of ptr ie address of a ......ptrr is also pointing where ptr is pointing
    cout<<ptrr<<endl<<*ptrr;

    // character pointer
    char ch='q';
    char*p=&ch;

    // note:

    ptr=ptr+1;  // it will shift ptr by bytes equal to that in type of dabba that it points once (initial byte included) and points to byte after that or we can say  it will shift the ptr by ek dabba (initial byte jisko yeh pooint krra is included in skipping dabba) of size equal to that of type of dabba that it points to and now it will point to the first byte after that 
    ptr=ptr+2;  // it will shift the ptr by two dabba of size equal to that of type of dabba that it points to and now it will point to the first byte after that or we can say it will shift by bytes equal to that in type of dabba that it points twice (initial byte included) and points to byte after that

     // note;

     // address[i] works as *(address+i) : will give value stored at address which is obtained after i shifting( i dabba shifting) of initial address

  // ptr[i] it will work as *(ptr+i) : will give value stored at address ptr+i or we can say initial address that ptr store mein i shifting ke baad wale address par stored value

    return 0;
}