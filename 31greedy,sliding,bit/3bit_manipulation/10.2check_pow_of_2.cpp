// given no, return true if it is any power of 2 else false
//eg given 16 -> it is 2 ki power 4 so ans is 4

 
// 2 ki power wale number ke binary m no of set bits is 1 always


// method 1 - number ke binary form mein  no of set bits count krlo and if it is 1 then true else false

//piche se ek ek bit lete rho and count krte rho
// #include<iostream>
// using namespace std ;
// bool checkPower0f2(int n) {
// //count set bit
// int count = 0;
// while(n != 0) {
// int lastbit = n & 1;
// if(lastbit) {
// count++;
// }
// n = n >> 1;
// }
// if(count == 1 ){
// return true;
// }
// else {
// return false;
// }
// }
// int main(){
//     int n=16;
//     cout<<checkPower0f2(n);
//     return 0;
// }



//  note:  n&(n-1) will give resultant which is equal to binary of n but with its last set bit  cleared or we can say first set bit from right cleared 

// m2
// if n&(n-1) ke baad it becomes zero then true (as mtlb 1 hi set bit thi) else false (as mtlb >1 set bits h )
// note : yeh 0 ko bhi true dega lekin ... so usko alag se sambhalna pdega .... baaki sab sambhal lega yeh.... +ve -ve sab

// #include<iostream>
// using namespace std ;
// bool fastCheckPower0f2(int n) {
// if(n==0) return false;             
// if((n & (n-1)) == 0)
// return true;
// else
// return false;
// }
// int main() {
// int n = 1024;
// cout << fastCheckPower0f2(n) << endl;
// return 0;
// }

// note : vse neg mein toh false hi hoga toh chaho usko bhi alag hi likhlo ....processing bachane k liye 

// #include<iostream>
// using namespace std ;
// bool fastCheckPower0f2(int n) {
// if(n<=0) return false;             
// if((n & (n-1)) == 0)
// return true;
// else
// return false;
// }
// int main() {
// int n = 1024;
// cout << fastCheckPower0f2(n) << endl;
// return 0;
// }



//lc 231

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if((n&(n-1))==0){
            return true;
        }
        else return false;
    }
};