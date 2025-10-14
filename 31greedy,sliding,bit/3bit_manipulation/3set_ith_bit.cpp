// set(make 1) ith bit(can be 0 or 1)  from right of a given decimal no and return updated decimal no

// masking
//mask wala(sab zero,ith wala 1) leke given se or krdo
// yeh mask banjayega 1<<i se
//note : initially voh bit 0 ho ya 1 dono case sambhal jaayeege  and finally 1 hi milega

#include<iostream>
using namespace std ;

void setIthBit(int n, int i) {
int mask = (1<<i);
n = n | mask;
cout << "Updated number: "<< n << endl;
}
int main() {
int n = 10;
int i = 2;
setIthBit(n,i);
return 0;
}