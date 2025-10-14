#include<iostream>
using namespace std ;
int main()
{

        // side n
    int n=5;  
    
    for (int row = 0; row< n; row++)
    {    
        //spaces 
        for (int col = 0; col < n-row-1; col++)
        {
            cout<<" ";
        }
        //ab stars lagado
          // first row mein 1 star...2nd row m 2 star and so on ie 0 index row mein 1 star ...1 index mein 2 and so on
         for (int i = 1; i <=row+1; i++)    // loop chalega rowidx+1 times
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
return 0;
}



