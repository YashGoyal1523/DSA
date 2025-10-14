// given an array print all possible pairs of elements

#include<iostream>
using namespace std ;

void printpairs1(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n; j++)
        {
            
           cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        }
        
    }
    return;
}

void printpairs2(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j= i; j < n; j++)        // j begins from i
        {
            
           cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        }
        
    }
    return;
}

void printpairs3(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n; j++)
        {
            if (i==j)
            {
                continue;
            }
            
           else cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        }
        
    }
    return;
}

void printpairs4(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j= i; j < n; j++)
        {
            if (i==j)
            {
                continue;
            }
            
           else cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        }
        
    }
    return;
}


int main()
{
    int arr[]={1,2,3};
    int n=3;
    printpairs1(arr,n);
    cout<<endl;
    printpairs2(arr,n);     // taking (a,b) and (b,a) as same
    cout<<endl;
    printpairs3(arr,n);   // not taking (a,a)
    cout<<endl;
    printpairs4(arr,n);     // taking (a,b) and (b,a) as same as well as not taking (a,a) 
return 0;
}



// triplets mein 3 nested loop