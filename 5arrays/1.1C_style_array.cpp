
// c style array 
#include<iostream>
using namespace std ;
int main()
{   
    

    int x[5];  // bada dabba made of chote dabbes created

    int a[]={1,2,3};   
   
    
    int arr[5]={1,2,3};
    cout<<arr[0]<<endl<<0[arr];      // i[arr] bhi likh skte for accessing

    
    int b[3];
    b[0]=1;


    cout<<endl<<endl;
    

    //addresses      ( address of array = base address ie add of zero index)

    cout<<&arr;// &arr give  address of array
    cout<<endl;
    cout<<arr;  //  arr is a constant pointer pointing to base address of array
     cout<<endl;
     cout<<&arr[0];   // address of 0 index   
    cout<<endl; 
    cout<<&arr[1]<<endl;          // address of 1 index

    cout<<*arr<<endl; // will give value of element at base dabba ie zero index
    cout<<*(&arr[0])<<endl; // will give value of element at 0 index


   // arr[i] and i[arr]  works at back as  *(arr+i) 


    cout<<endl;


    //size of array
    cout<<sizeof(arr);  // total space of array : 5*4=20 bytes //The sizeof(arr) will give you the size of the entire array in bytes and not size of pointer dabba. This is because the array name arr in this context is not a pointer but an array variable, and sizeof applied to an array variable gives the total size of the array.

    cout<<endl;

    // no of elements of array
    cout<<sizeof(arr)/sizeof(int);
    
    cout<<endl;

    // note
    int brr[4]={2,3}; // less initialised
    cout<<brr[2]<<endl; // garbage value is stored at index 2 and 3

    cout<<&brr<<endl<<&brr+1<<endl<<&brr+2;

    
    return 0;
}


// arr[index]: ie accessing indexes cant be done jabtak voh index ka dabba create nhi huaa ho..... yaaani if we make int arr[4]; and try to access arr[6] then it will show error as uska dabba banaya hi nhi humne...(dabbe are made when we declare size)


// note: int arr[5]={1} ; the first element of the array is explicitly initialized to 1, and all other elements are implicitly initialized to 0 as well.
//       int arr[5]={0} ; the first element of the array is explicitly initialized to 0, and all other elements are implicitly initialized to 0 as well.
//       int arr[5]={1,2,3}; phle teen explicitly 1,2,3 baaki implicitly 0




// genrally but system based
// note:int char  double  array ka max size allowed is 10^6
//      global array int char double ka max size is 10^7
//      global array bool  ka max size is 10^8




