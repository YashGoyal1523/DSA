#include<iostream>
using namespace std ;



 void maximum(int a,int b, int c){

        // if (a>b && a>c) cout<<"max is : "<<a;
        // else if (b>a && b>c) cout<<"max is : "<<b;
        // else cout<<"max is : "<<c;


           int ans1=max(a,b);           // use inbuilt func in c++ :max()  (for two nos)
           int ans2=max(ans1,c);
           cout<<"max is "<<ans2;
    }

int main()
{
    int a,b,c;
    cout<<"enter nos";
    cin>>a>>b>>c;
    maximum(a,b,c);
   
return 0;
}