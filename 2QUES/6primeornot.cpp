#include<iostream>      // check whether prime or not
using namespace std ;      


// prime no: which is divisible only by 1 and itself ie have factors only 1 and itself

bool checkprime(int n){
    for (int i = 2; i < n; i++)  
    {
        if (n%i==0)
        {
            return false;             // taking ->  return false : no prime , return true : prime
        }                             // bool ki jagah dusra dataypte bhi le skte jse int fir integer return krlo kuch
        
    }
    return true;         // note: if n=a*b then  1<=...a...<=sqrt(n)<=...b...<=n     // so note isko thoda optimise krne ke liye loop i<=sqrt(n) tak hi chalalo ....as uske baad  agar koi no se divisible hoga  toh uska other factor yaani jisse voh multiply hoke no banayega voh sqrt se phle mein hi aayega toh voh phle wale mein hi ans miljayega..... so vhi tak check kro kyuki agar phle hi nhi mila toh aage bhi nhi hi milega for sure
}
int main()
{
    int n;
    cout<<"inpuut n";
    cin>>n;
    bool prime=checkprime(n);
    if (prime)        // if (prime==true)
    {
        cout<<"yes prime";
    }
    else cout<<"no prime";
return 0;
}