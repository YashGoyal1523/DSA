
//given an array of some elements positive and some negative.arrange all negative to left and pos to right. order maintain not required

// way 1 : sorting 

// way 2  : 2 pointer method
#include<iostream>                      
using namespace std ;
int main()
{
    int arr[]={-1,2,4,5,-2,-6,-8};
int n=7; // size

// printing array
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

cout<<endl;

// arranging 

// // method 1  swap_1

// int j=0;  //  j : index variable which stores -ve....j ek baar starting par rkhdia

// for (int i = 0; i <n; i++)       // traversing in array  

// {
//    if (arr[i]<0)
//    {
//     swap(arr[i],arr[j]);
//     j++;
//    }
   
//   // else continue;   ..... likho na likho ek hi baat hai....likhoge toh bhi jab if satisfy nhi hoga toh else aake continue hogaa and normal agla iteration chalega updation hoke...nhi likhoge toh bhi jab if satisfy nhi hoga toh aage kuch nhi h toh next par hi jaayega...toh ek hi baat hai
// }            //  // sab -ve left m lagte gye toh +ve right m aagye sab toh done....

// // printing updated array
// for (int i = 0; i < n; i++)
// {
//     cout<<arr[i]<<" ";
// }

// method 2 : swap_2 

int i=0, j=n-1;  // traversing indexes from front and back
while(i<j){
if(arr[i]<0){
i++;
}
else if(arr[j]>0){
 j--;
}
else{
swap(arr[i],arr[j]);
}
}

// printing updated array
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}


// // method 3  new array_1
// int brr[n];    // new array jisme arrange krke rkhege

// int i=0;  // i: index which stores -ve in new arr   i ek baar starting m rkhdia
// int j=n-1;  // j:index which stores +ve in new arr   j ek baar ending par rkhdia

// for (int a = 0; a < n; a++)    // traversing in array
// {
//     if (arr[a]<0)
//     {
//         brr[i]=arr[a];
//         i++;
//     }
//     else {
//         brr[j]=arr[a];
//         j--;}
// }



// cout<<endl;


// // printing new array
// for (int i = 0; i < n; i++)
// {
//     cout<<brr[i]<<" ";
// }

return 0;
}

// two pointer can also be used in arranging 0 and 1 wala ques...



// // 2 pointer ka method 4 (new array_2) for arranging 0 ,1  

// int i=0; // i: index which stores 0
// int brr[n];

// for (int a = 0; a< n; a++)    // traversing in array
// {
//     if (arr[a]==0)
//     {
//         brr[i]=0;
//         i++;
//     }
    
// }

// // 0 place hogye...ab 1 krre remaining par....i vaha aagya jaha se 1 shuru hoga

// for (int a = i;  a < n; a++)
// {
//     brr[a]=1;
// }


// print brr

