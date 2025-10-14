// when range is in middle instead of starting rightmost 

// clear the bits in the range from jth bit to ith bit (i>j)        11111111111
//                                                                     i   j
// mask(range wale 0 baaki 1) ka & krdo no se
// to make this mask-  -1<<(i+1) , ~(-1<<j) ka |  (or) lelo


#include<iostream>
using namespace std ;
void clearBitsInRange(int n, int i, int j) {
int a = (-1 << (i+1));
int b = ~(-1 << j);
int mask = a | b;
n = n & mask;
cout << "Updated number: "<< n <<endl;
}
int main()
{
    int n=1023;
    int i=8;
    int j=1;
    clearBitsInRange(n,i,j);
return 0;
}