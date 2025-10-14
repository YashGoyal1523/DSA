#include<iostream>                      // step 1 check no of rows for outer loop...step 2 observe columns in each row for inner loop
using namespace std ;
int main()
{   //  4 by 4 square
    
    for (int i = 0; i < 4; i++)        //  row  //row index <=3
    {
        for (int i = 0; i < 4; i++)     // columns
        {
            cout<<"* ";       // ek space bhi diya hai taaki clean lage
        }
        cout<<endl;
    }
    
return 0;
}
