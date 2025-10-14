// binary no is 0 indexed from right
// tell ith bit in binary form of given decimal no

//m1
//  given no ko i baar right shift krdo fir & 1 krdo ...isse miljayega
// (n>>i) & 1 : gives 0 then bit 0 , gives 1 then bit 1

//m2
// masking method - ek binary no(mask) banao with ith bit 1 and sab 0 ..ab iska given no. ke binary se & krdo if resultant decimal no is zero then bit is 0 and if non zero resultant then it is 1.....yeh mask banjayega 1<<i se

#include<iostream>
using namespace std ;

void getIthBit(int n,int i) {
int mask = (1 << i);    // isse hume required binary no miljayega // 1<<k -> 1000(kzeroes) // 1000 is equal to ....0001000 
int ans = n & mask;
if(ans == 0) {
cout << "bit-> 0" << endl;
}
else {
cout << "bit-> 1" << endl;
}
}
int main(){
int n = 10;
int i = 20;
getIthBit(n, 1);
return 0;
}




// application
// note: hume no ke ek ek krke saare 32 bits chahie 

//m1
// for(int i=0;i<32;i++){
//     int bit=n&1;
//     n=n>>1;
// }

// m2
// for(int i=0;i<32;i++){
//     int bit=(1<<i)&n;
// }


// tip : 1<<i = pow(2,i)