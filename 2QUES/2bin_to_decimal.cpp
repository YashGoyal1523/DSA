#include<iostream>
#include<cmath>
using namespace std ;


int convert(int n){

    int decimal=0;

    int i=0;
    while(n>0){
        int bit=n%10;  // first iteration mein binary ka last bit uthaalia ....agle mein fir remaining ka last uthaalege ie original ka second last and so on
        decimal=decimal+bit*pow(2,i);  //first iteration ie last bit ko 2^0 se ..second iteration ie second last ko 2^1 se ...so on... multiply and add all
        n=n/10;  // for last bit remove
        i++;
    }


// another way to write

//  int i=1;
//     while(n>0){
//         int bit=n%10; 
//         decimal=bit*i+decimal;  
//         n=n/10; 
//         i=i*2;
//     }





    return decimal;
}

int main()
{
    int n;
    cout<<"enter number";
    cin>>n;
    cout<<convert(n);
return 0;
}


// note: 

// given binary no

// string bin="10101"

//convert to decimal no

//m1 left to right traverse
//m1.1
int n=bin.size();
int power=n-1;
int dec=0;
for(int i=0;i<n;i++){
    dec+=pow(2,power)*bin[i];
    power--;
}
return dec;

//m1.2 bit manipulation
    int n=bin.size();
    int dec = 0;
    for (int i=0;i<n;i++) {
        dec = (dec << 1) | bin[i];   //or   dec = (dec*2) | bin[i];  or dec = (dec*2) + bin[i];    
    }
    return dec;


//m2 right to left traverse

int n=bin.size();
int dec = 0;
int base = 1;
for (int i = n - 1; i >= 0; --i) {
    dec += bin[i] * base;  
    base=base*2; //base=base<<1;     // multiply base by 2
}
return dec;

