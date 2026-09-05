#include<iostream>
using namespace std ;


// stl
// gcd(a,b) fn  : numeric header file



// normal method to find gc
int gcd_1(int a,int b){
    int smaller=min(a,b);
    int ans=0;
    for(int i=smaller;i>=1;i--){
        if(a%i==0&&b%i==0){
             ans=i;
             break;
        }
    }
    return ans;
}


// gcd - using euclid algorithm 

//subtraction version

int gcd_2(int a,int b){

    while(a>0&&b>0){
        if (a>b)
        {
            a=a-b;
        }
        else b=b-a;
    }
    return a==0? b:a;
}

//modulo version
int gcd_3(int a, int b) {
    while (b != 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=gcd_1(a,b);
    cout<<ans;
return 0;
}




// gcd(x, y, z) = gcd(gcd(x, y), gcd(y, z))
