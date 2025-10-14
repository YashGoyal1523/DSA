#include<iostream>
using namespace std ;
int main()
{
    int arr[2][2];
    int row=2;
    int col=2;

    for (int i = 0; i < row; i++)    // for row...i row index
    {
       for (int j = 0; j < col; j++)    // for col ...j col index
       {
        cin>>arr[i][j];

       }
       
    }             // row wise input


    // similarly we can also take col wise input


    //  for (int i = 0; i < col; i++)   // //for col ...i col index
    //  {
    //    for (int j = 0; j < row; j++)    //// for row   ... j row index
    //    {
    //     cin>>arr[j][i];       //// arr[row][col]

    //    }
       
    // }      
    
return 0;
}