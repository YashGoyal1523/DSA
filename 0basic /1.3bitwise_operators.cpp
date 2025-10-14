#include<iostream>      // bitwise operators  - works at bits level
using namespace std ;
int main()
{
//    and & ,or | ,  nor ~ ,  xor ^

    int a=1,b=4;
    int c=a&b;
    int d=1&4;
    cout<<(a&b)<<endl<<c<<endl<<d;          //    cout<< ke baad bracket lena padega for  '&' , '|', '^' and no need for '~' 
    cout<<endl;
    cout<<~a<<endl<<(~a)<<endl<<~(a);
    cout<<endl;
    cout<<(a|b);
     cout<<endl;
    cout<<(a^b);


// tip : in signed integer case : nor of decimal no k is decimal no -(k+1)            ~k(decimal no) = -(k+1) (decimal no)


// shift operators -  >> , <<

int e=2;
    int f=e<<1;
    int g=e>>1;
    cout<<f<<endl<<(e<<1)<<endl<<g<<endl;        // bracket lagana hi pdega


    // note:
    
    // 1 ka binary is 0000000...01      ,     1(decimal no) ka left shift k times becomes 1000...0(k zeros) (binary no) (1 at kth bit baaki bits 0)   or 2^k (decimal no)           
    int h=1<<2;
    cout<<h;

    // note: 
    
    // -1 ka binary is 1111.....111    ,     -1<<k will give 11....1111000..0(kzeroes) (binary no) (k-1th bit tak 0 baaki bits 1 ie right se k bits 0 baaki bits 1)

    
return 0;
}

// xor operation is commutative ,associative
// note : if a^b=c => a^c=b , b^c=a