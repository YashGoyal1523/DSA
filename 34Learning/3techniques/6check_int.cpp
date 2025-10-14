// given a no x...checking whether its integer or not

#include<iostream>
using namespace std ;
int main()
{
    double x;
    cin>>x;
    if(x==(int)x) cout<<"yes";
    else cout<<"no";
 
return 0;
}

// to check if x/y is integer or not

#include<iostream>
using namespace std ;
int main()
{
    int x,y;
    cin>>x>>y;
    //m1
    double q=(double)x/y;
    if(q==(int)q) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

    //m2
    if(x%y==0) cout<<"yes"<<endl;
    else cout<<"no"<<endl;

return 0;
}
