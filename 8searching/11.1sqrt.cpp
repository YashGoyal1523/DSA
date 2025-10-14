
// 1. find square root . if not integer then -1

//  search space -> [0,n]

//bruteforce-linear search

//optimal-binary search : o(logn)
// #include<iostream>
// using namespace std ;

// int mysqrt(int n){

//     int start=0;  //  search space -> [0,n]
//     int end=n;
    

//     while (start<=end)
//     {
//         int mid=start+(end-start)/2;

//        //is mid the ans....(predicate function)
//         if (mid*mid==n)
//         {
//             return mid;
//         }
//         else if (mid*mid>n)
//         {
//             // left aoo
//             end=mid-1;
//         }
//         else {       // mid*mid<n
//             //right aao          
            
//             start=mid+1;
//         }
//     }
    
// return -1;
// }


// int main()
// {
//     int n;
//     cout<<"enter no";
//     cin>>n;
//     int ans=mysqrt(n);

//     cout<<ans;


// return 0;
// }









// 2. find square root   (68 ka 8)

//  search space -> [0,n]

//bruteforce-linear search

//optimal-binary search : o(logn)
#include<iostream>
using namespace std ;

int mysqrt(int n){

    int start=0;  //  search space -> [0,n]
    int end=n;
    int ans=-1; // yeh rkhna pdega for 68 ka 8 laane k liye

    while (start<=end)
    {
        int mid=start+(end-start)/2;

       //is mid the ans....(predicate function)
        if (mid*mid==n)
        {
            return mid;
        }
        else if (mid*mid>n)
        {
            // left aoo
            end=mid-1;
        }
        else {       // mid*mid<n
            // ans store ...right aao          ...store krna padra as  for getting 8 ans for 68
            ans=mid;
            start=mid+1;
        }
    }
    
return ans;
}


int main()
{
    int n;
    cout<<"enter no";
    cin>>n;
    int ans=mysqrt(n);

    cout<<ans;


return 0;
}

