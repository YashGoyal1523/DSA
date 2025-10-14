// given a no n.. print all its factors


//naive

// #include<iostream>
// using namespace std ;
// int main()
// {
//     int n;
//     cin>>n;

//     for(int i=1;i<=n;i++){
//         if(n%i==0) cout<<i<<" ";
//     }
 
// return 0;
// }



//optimised

// note: if n=a*b then   1<=...a...<=sqrt(n)<=...b...<=n      // so note isko thoda optimise krne ke liye loop <=sqrt(n) tak hi chalalo ....as uske baad  agar koi no se divisible hoga  toh uska other factor yaani jisse voh multiply hoke no banayega voh sqrt se phle mein hi aayega toh voh phle wale mein se dusra bhi ans miljayega..... so vhi tak check kro 

#include<iostream>
using namespace std ;
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=sqrt(n);i++){ //or i*i<=n
        if(n%i==0) cout<<i<<" "<<n/i<<endl;
    }
 
return 0;
}