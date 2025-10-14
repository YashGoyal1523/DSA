#include<iostream>
using namespace std ;

int minimum(int arr[][2],int row,int col){
    int min=INT_MAX;
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        if (arr[i][j]<min)
        {
            min=arr[i][j];
        }
        
    }
    
}
return min;
}

int maximum(int arr[][2],int row,int col){
    int max=INT_MIN;
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
    {
        if (arr[i][j]>max)
        {
            max=arr[i][j];
        }
        
    }
    
}
return max;
}





int main()
{
int arr[2][2]={1,2,3,4};
int row=2;
int col=2;

int min=minimum(arr,row,col);
int max=maximum(arr,row,col);


cout<<min<<endl<<max;

return 0;
}