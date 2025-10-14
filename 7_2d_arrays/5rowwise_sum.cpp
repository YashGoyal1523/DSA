#include<iostream>
using namespace std ;
int main()
{
    int arr[2][2]={1,2,3,4};
    int row=2;
    int col=2;

    for (int i = 0; i <row; i++)
    {   int sum=0;
        for (int j = 0; j < col; j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<"sum of row "<<i+1<<" "<<"is "<<sum<<endl;
    }
    

return 0;
}