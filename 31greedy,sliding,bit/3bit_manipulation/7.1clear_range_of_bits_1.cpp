// note: -1 ka binary is 111....1111     ,  -1<<k will give 11....1111000..0(kzeroes) (binary no) (k-1th bit tak 0 baaki bits 1 ie right se k bits 0 baaki bits 1)


// clear the bits in the given range from 0th bit to ith bit (i+1 bits from right)

// mask(sab 1,range wale 0) ke saath & krdoo
// yeh mask banane kliye -1<<i+1 krlo 


#include<iostream>
using namespace std ;

void clearLastIBits(int n, int i) {
int mask = (-1 << (i+1));
n = n & mask;
cout << "Updated number: " << n << endl;
}
int main() {
int n = 15;
int i = 2;
clearLastIBits(n, i);

return 0;
}