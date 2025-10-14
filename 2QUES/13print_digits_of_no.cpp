// given no (>=0). print its digits from ones to leftwards

#include<iostream>
using namespace std ;

void digits(int n){
    while(n>0){
        int lastdigit=n%10;
        cout<<lastdigit<<endl;
        n=n/10; // update no
    }
    return ;
}



int main()
{
    int n=1234;
    digits(n);
return 0;
}
