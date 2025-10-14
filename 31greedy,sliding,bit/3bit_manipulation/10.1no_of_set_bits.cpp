//no of set bits

//(bruteforce to count set bits is ek ek krke piche se bits nikalte rho( bit=n&1 ,n=n>>1 wale se ya divisioon wale se bit=n%2 , n=n/2 ) and count++ krte rho if set)
// int count = 0;
// while(n != 0) {
// int lastbit = n & 1;
// if(lastbit) {
// count++;
// }
// n = n >> 1;
// }

// another method...
// get ith bit wale method se....ek ek krke saare bits check krlo
//  int cnt=0;
// for(int i=0;i<=31;i++){
//     if(n&(1<<i)==1) cnt++;
// }

//another method
//  note:  n&(n-1) will give resultant which is equal to binary of n but with its last set bit  cleared or we can say first set bit from right cleared 
// jitni baar yeh formula lagega to make resultant zero will give no of set bits 

#include<iostream>
using namespace std ;

int fastCountSetBits(int n) {
int count = 0;
while(n != 0) {         
n = (n & (n-1));
count++;
}
return count;
}

int main()
{ int n=16;
cout<<fastCountSetBits(n);
return 0;
}


// inbuilt function in c++ to count no of set bits
// __builtin_popcount(n)