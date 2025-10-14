
// extreme print: if array is 1,2,3,4,5  then extreme is 1,5,2,4,3....first last second second last so on



#include<iostream>
using namespace std ;

void extremeprint(int arr[],int size){



        int leftindex=0;
        int rightindex=size-1;

        // while (leftindex<rightindex)     // chahe < ho ya <= ho yeh even no of elements mein toh chal jaayega par dono odd no of elements case m dikkat dege as < case mein dikkat hogi ki odd no of elements case mein mid print nhi hoga and <= nhi krna as usme fir odd no of elements case m mid wala do baar hojayega
        // {
        //     cout<<arr[leftindex]<<" ";
        //     cout<<arr[rightindex]<<" ";
        //     leftindex++;
        //     rightindex--;
        // }

// toh odd no of elements bhi thik chale isiliye
 while (leftindex<=rightindex)     
        { if (leftindex==rightindex)
        {
            cout<<arr[leftindex];
        }
        
            else {cout<<arr[leftindex]<<" ";
            cout<<arr[rightindex]<<" ";
            }
            leftindex++;
            rightindex--;
        }
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

    cout<<endl;

    extremeprint(arr,size);            // array is passed by reference

    
  
    
return 0;
}