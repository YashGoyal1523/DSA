#include<iostream>             // take input digits and form no from it
using namespace std ;

int number(int n){                   
    int ans=0;
    for (int i = 0; i < n; i++)
    {   int digit;
        cout<<"enter digit ";
        cin>>digit;
        ans=ans*10+digit;        // first entered digit on left then rightwards........note: for first digit on rightt then leftwards ...ese krne k liye  m1 : left to rightwards krke reverse krlo .....m2: seedha hi vse lagao ......int k=0 ; ans=ans+digit*pow(10,k++) ;   se
    }                                                                                                                                                                                                                                                                                       
    return ans;
}


int main()
{
    int n; // no of digits
    cout<<"enter no of digits";
    cin>>n;
    int num=number(n);
    cout<<"number is "<<num;
return 0;
}