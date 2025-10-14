// given an array nums with n objects colored red ,white,blue....sort them in order red white blue....use integer 0,1,2, for red white blue resp...
// alt ques...given array with elements as 0,1,2....arrange this in order 0,1,2.



// way 1 -sorting

// way 2- counting no of 0,1,2 and then shuru se phle 0 place krdo utne fir 1 utne fir 2 utne




// way 3 - 2 pointer method
#include<iostream>
using namespace std ;
int main()
{
    int nums[]={0,2,2,1,0,1,2};
    int n=7;


// // method 1  new array
//     int arr[n];

//     int i=0;   // stores 0
//     int j=n-1;  // stores 2

//     for (int a = 0; a < n; a++)
//     {
//         if (nums[a]==0)
//         {
//             arr[i]=0;
//             i++;
//         }
//         else if (nums[a]==2)
//         {
//             arr[j]=2;
//             j--;
//         }
        
        
//     }
//     // 0,2 arranged....ab bich m 1 lagana bas....i vaha pahuch gya jaha se 1 aayega ...j vaha pahuch gya jaha tak 1 aayega


//     for ( int a = i; a<=j; a++)
//     {
//        arr[a]=1;
//     }
    

    // // printing

    // for (int a = 0; a < n; a++)
    // {
    //     cout<<arr[a]<<" ";
    // }
    



  // method 2 swap

// int i=0; // i : index which stores 0
// int j=n-1; // j: index which stores 1

// for (int a = 0; a <=j; a++)   // traversing array......note j ko cross na ho traverse index as...fir uske baad vaha 2 milega usse and fir swap hojayega and ab tak j 2 ki positions se aage ja chuka hoga and swap hoke fir bigad jaayega
// {
//     if (nums[a]==0) 
//     {
//         swap(nums[a],nums[i]);
//         i++;
//     }
//     else if (nums[a]==2)
//     {
//         swap(nums[a],nums[j]);
//         j--;
//     }                           

// else {   // ==1 wala 
//     continue;   // kuch nhi krna aage bhadho
//       }    // yeh continue case na bhi likhe toh bhi functioning ese hi hogi ...bas understanding k liye

// }

// // NOTE:
 // // yeh galat haii as jab 2 aara and usko swap krre toh agar other element is 1 ya 2 toh dikkat hojayegi as traversing index toh aage chala jaayega fir voh swapped 1 ya 2 vhi rehjayega and dikkat de skta hai....toh yeh thik krne k liye 2 par updation nhi chahie traversing index ka and yeh while loop se hoga as for mein updation rok nhi skte...

// correct for swap:  DUTCH NATIONAL FLAG ALGO

int a=0; // traversing index
int i=0; // stores 0
int j=n-1; // strores 2

while (a<=j)        //note krna yeh bhi         // jab tak traversing index right se aane wale ko cross na kar jaaye   as...fir uske baad vaha usko 2 milega and fir 2 wala case lag ke  swap hojayega and ab tak j 2 ki positions se aage ja chuka hoga and swap hoke fir bigad jaayega
{
   if (nums[a]==0)
   {
    swap(nums[a],nums[i]);
    i++;
    a++;
   }
   else if (nums[a]==2)
   {
        swap(nums[a],nums[j]);
        j--;
        //  a++; yeh nhi krna as kya pata swap hoke 2 hi aagya ho
   }
   else a++;   // ==1 case mein kuch nhi aage badho
   
}




// printing

for (int b = 0; b < n; b++)
{
  cout<<nums[b]<<" ";
}



return 0;
}