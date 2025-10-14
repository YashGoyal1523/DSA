#include<iostream>                                     
using namespace std ;
int main()
{    // 4 by 3
    for (int i = 0; i < 3; i++)        //  row
    {
        for (int j = 0; j < 4; j++)     // columns
        { 
          // stars  (if first(0 index) or last(n-1 index) row / column (boundary))
           if (i==0 ||i==2 ||j==0 ||j==3)
           {
             cout<<"* ";        // space clean k liye
           }
           //space
           else cout<<"  ";   // double space    phli space for hollow ,dusri space clean wale ke liye
        }
        cout<<endl;
    }
    
return 0;
}