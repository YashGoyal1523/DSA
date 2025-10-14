
#include<iostream>    // print prime no from 1 to n
using namespace std ;

bool checkprime(int n){
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return false;             
        }                             
        
    }
    return true;
}
int main()
{
    int n;
    cout<<"input n";
    cin>>n;

    for (int i = 2; i <=n; i++)      // 1 kuch nhi hota toh 2 se shuru krre
    {
        bool prime=checkprime(i);
    if (prime)       
    {
        cout<<i<<endl;
    }
    
    }
    
    
return 0;
}