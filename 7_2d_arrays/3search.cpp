#include<iostream>
using namespace std ;


bool find(int arr[2][2],int row,int col,int target){

    for (int i = 0; i < row; i++)
    {
       for (int j = 0; j < col; j++)
       {
        if (arr[i][j]==target)
        {
            return true;        // true for found
        }
        
       }
       
    }
    return false;   // false for not found
}





int main()
{
int arr[2][2]={{1,2},{3,4}};
int row=2;
int col=2;
int target=4;

cout<<"ans "<<find(arr,row,col,target);
return 0;
}