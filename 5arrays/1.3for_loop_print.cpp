
// for( _ x : y){        //_ is 'datatype of elements of y'  // y should be of collection of elements datatype
//                            // will pick each element belonging to y one by one ....iteratively.....and in each iteration create ....a copy element(in case of x) and alias(nickname) (in case of &x) ..... note: inka scope yeh for loop ke andar hi hoga
//  }                      



// note:

// for (int &a : y){

// }
// This loop uses a reference (int &a), meaning a is an alias(nickname) for the elements of the container y.
// Any modifications to a will directly affect the elements in y

// for (int a : y){

// }
// This loop uses a value (int a), meaning a is a copy of each element in the container y.
// Any modifications to a will not affect the elements in y.
// It involves copying each element




#include<iostream>
using namespace std ;
int main()
{
    int arr[5]={1,1,1,1,1};
    //printing
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;

    for( int i : arr){   // i belongs to arr 
        cout<<i<<" ";
    }

   
    cout<<endl;

     for( auto i : arr){
        cout<<i<<" ";
    }

      cout<<endl;

    for( int &i : arr){  
        i=-1;
    }

    for( auto i : arr){
        cout<<i<<" ";
    }


return 0;
}