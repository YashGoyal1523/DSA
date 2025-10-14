#include<iostream>
using namespace std ;


// stl
// gcd(a,b) fn  : numeric header file



// normal method to find gc
int gcd_1(int a,int b){
    int smaller=min(a,b);
    int greater=max(a,b);
    int ans=0;
    for(int i=1;i<=smaller;i++){
        if(smaller%i==0&&greater%i==0){
             ans=i;
        }
    }
    return ans;
}


// gcd - using euclid algorithm 

int gcd_2(int a,int b){
    
    if(a==b) return a;

    //gcd(a, 0) = |a|, for a ≠ 0, since any number is a divisor of 0, and the greatest divisor of a is |a|.
    if (a==0) return b;
    if (b==0) return a;

// euclid 
    while(a>0&&b>0){
        if (a>b)
        {
            a=a-b;
        }
        else b=b-a;
    }
    return a==0? b:a;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=gcd_1(a,b);
    cout<<ans;
return 0;
}



