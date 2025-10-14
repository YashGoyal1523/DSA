// given no. n, represent it in min count of powers of 2

// eg 6=2^2+2^1 ->2 required
// eg 7=2^2+2^1+2^0 ->3 required
// eg 8=2^3 ->1 required

// approach : 
//n ki binary representation mein set bits ko dekhlo
//har set bit ke corr 2 ki pow lelo to represent it in min count of powers of 2
//min count required = no of set bits

// 6= 110 -> 2 set bits -> 2^2+2^1 ->2 required

// note : 
//max count of powers of 2 that can be used to reprsent= n (2^0+2^0+2^0+...n times)

// we can represnt n in any count value of powers of 2 ranging in [no of set bits , n]

#include <bits/stdc++.h>
using namespace std;                

int main() {
    int n;
    cin>>n;
    int cnt=0;
    int pow=0;
    while(n){
        if(n&1){ //lsb is set
            cnt++;
            cout<<"2"<<"^"<<pow<<" ";
        }
        n=n>>1; //right shift to remove lsb
        pow++;
    }
    cout<<" Min count = "<<cnt<<endl;
    return 0;
}

