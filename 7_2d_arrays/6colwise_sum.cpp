#include<iostream>
using namespace std ;
int main()
{
    int arr[2][2]={1,2,3,4};
    int row=2;
    int col=2;

    for (int i = 0; i <col; i++)
    {   int sum=0;
        for (int j = 0; j < row; j++)
        {
            sum=sum+arr[j][i];
        }
        cout<<"sum of col "<<i+1<<" "<<"is "<<sum<<endl;
    }
    

return 0;
}