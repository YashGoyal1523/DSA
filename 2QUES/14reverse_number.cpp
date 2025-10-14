//note :
// int/int gives int
// now 
// n is int
// n%10 gives last digit of n with sign that of n //21%10=1 , -21%10=-1
// n/10 gives output with last digit removed with same sign //21/10=2 (2.1 is 2 in int) , -21/10=-2  (-2.1 is -2 in int)



// return the reverse no of given integer number (>=0)
#include<iostream>
using namespace std ;

int reverse(int n){
    int number=0;
    while(n>0){
        int lastdigit=n%10;
        number=(number*10)+lastdigit;
        n=n/10; // update no
    }
    return number;
}

int main()
{
    int n=12234;
    cout<<reverse(n);
return 0;
}


// to handle -ve integer also 

//use this fn

// int reverse(int n){
//     int number=0;
//     while(n!=0){
//         int lastdigit=n%10;
//         number=(number*10)+lastdigit;
//         n=n/10; // update no
//     }
    
//      return number;

// }
