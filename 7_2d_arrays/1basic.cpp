#include<iostream>
using namespace std ;

void print(int arr[1][2],int row,int col){      // no of col dalna compulsory chahe row daalo ya nhi....and exact vhi no daalna jitni col h na kam na zyada...row m kuch bhi daal skte
// row wise printing of array will give desired structure 

    for (int i = 0; i < row; i++)       // outer loop for rows ...i:row index maanlo
    {
        for (int j = 0; j < col; j++)     // inner loop for col....j:col index maanlo
        {
            cout<<arr[i][j]<<" ";          //arr[row][col]
        }
        cout<<endl;
    }         
                    
    return;
}

void colwiseprint(int arr[][2],int row,int col){

    for (int j = 0; j < col; j++)   //outer loop for col... j:col index
    {
        for (int i = 0; i < row; i++)   //  inner loop for row...i:row index
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

// or another way of writing

//  for (int i = 0; i < col; i++)   // //for col i: col index
    //  {
    //    for (int j = 0; j < row; j++)    //// for row  j: row index 
    //    {
    //     cout<<arr[j][i]<<" ";     ////arr[row][col]

    //    }
     //   cout<<endl;
    // }     


    return;               // col wise print of array will not give desired array but transpose of it
}



int main()
{
    int arr[][2]={     // no of col dalna compulsory chahe row daalo ya nhi
        {1,2},
        {3,4}
        };

int row=2;
int col=2;

print(arr,row,col);        // passed by reference

cout<<endl;

colwiseprint(arr,row,col);

return 0;
}

