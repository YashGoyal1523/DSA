// note     +/+ = +  ,  -/- = -   ,  +/- ya -/+  = - 


// note    int n=-5;
//          int x=abs(n);  ==> x=5





//given two nos divide them and find ans using binary search
//...(29/7=4)...
//nos can be +ve,-ve
#include<iostream>
using namespace std ;

int quotient(int divisor,int dividend){
    int s=0;  // search space->[0,dividend]
    int e=dividend;
    int ans=-1;

    while(s<=e){
       int mid=s+(e-s)/2;
        if(mid*divisor==dividend){
            return mid;
        }
    if(mid*divisor<dividend){
        // ans store.....right m jao ..... store krna pada for 4 of 29/7
        ans=mid;
        s=mid+1;
    }
    else                //(mid*divisor>dividend)
    // left m jao
    e=mid-1;


    }


return ans;

}


int main()
{
    int divisor=-7;     
    int dividend=29;

    int ans=quotient(abs(divisor),abs(dividend));  // fn works for both positive....ek baar toh positive leke ans nikalo fir aage dekhlege 

    // abhi ans is +ve ...now we need to find agar -ve aana chahie toh -ve kro vrnaa as it is rhne do

    if( (divisor>0&&dividend<0)|| (divisor<0&&dividend>0)){
        ans=0-ans; // ans=(-1)*ans;
    }

    cout<<"final ans : "<<ans;
return 0;
}


// try divide prperly.....29/7=4.__