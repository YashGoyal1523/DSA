// given an array with elements 0 and 1. arrange all zero to left and 1 to right


// m1 : sorting

// m2 : using counting method: first count no of 0s and 1s then shuru se start hoke phle utne 0 place krdo fir utne 1
#include<iostream>
using namespace std ;
int main()
{

int arr[]={0,1,1,1,0,0,1,0};
int n=8;

// printing array

for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

cout<<endl;

// counting 
int zero=0;
int one=0;
for (int i = 0; i < n; i++)
{
   if (0==arr[i])   // note arr[i]==0 and 0==arr[i]  is same
   {
    zero++;
   }
   else one++;
}
// // placing zero first


// int i;     // bahar likha as use krna hoga aage
// for ( i = 0; i <zero ; i++)
// {
//     arr[i]=0;
// }

// // now place one    // // note ab yaha i has reached that index jaha se 1 aane h

// for (int j = i;  j<n ; j++)
// {
//     arr[j]=1;
// }


//placing zero first

int i=0;

while (zero--)   // equivalent to  while(zero!=0) {......zero--;}   // note: no of iterations is equal to value initial value of variable zero
{
    arr[i]=0;
    i++;
}

// now placing one   // note ab yaha i has reached that index jaha se 1 aane h

while (one--)
{
    arr[i]=1;
    i++; 
}


// printing array

for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

return 0;
}
