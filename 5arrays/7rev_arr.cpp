// reverse without using another array 


//method:two pointer:- swapping first and last....second and second last ...so on
#include<iostream>
using namespace std ;

void revarray(int arr[],int size){

// for (int leftindex = 0,rightindex=size-1; leftindex<=rightindex;  leftindex++,rightindex--)
// {
//     swap(arr[leftindex],arr[rightindex]);         // swap()  : inbuilt func in c++
// }

        int leftindex=0;
        int rightindex=size-1;
        while (leftindex<=rightindex)        // < se bhi hojayega
        {
            swap(arr[leftindex],arr[rightindex]);      // swap()  : inbuilt func in c++
            leftindex++;
            rightindex--;
        }
//printing reversed
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }


        return;
}

int main()
{
    int arr[5]={1,2,3,4,5};
    int size=5;
    //printing original
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    revarray(arr,size);            // array is passed by reference

    cout<<endl;
    //printing reversed
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
return 0;
}