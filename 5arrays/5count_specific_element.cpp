#include<iostream>
using namespace std ;     // count no of 1s and 0s

void count(int arr[],int size){
    int one=0;
    int zero=0;

for (int i = 0; i < size; i++)
{
    if (arr[i]==1)
    {
        one++;
    }
     if (arr[i]==0)
    {
        zero++;
    }
}
cout<<"one is"<<one<<endl<<"zero is"<<zero;
return;
}




int main()
{
int arr[]={1,1,3,4,0,8,0,4,3};
count(arr,9);
    
return 0;
}

// note : stl use kr skte
// we can use count() fn :  <algorithm> header file
// count(firstpos,lastpos,value to be counted) : counts the frequency of value in range [first,last) and return it
// to find in range [start,end] do count(startpos,next to end pos,value) 

// eg 
// vector<int>v={1,2,3,1,3};
// to count 1
// do
//int ans=count(v.begin(),v.end(),1);

//eg
// string s="yyyash";
// to count 'y'
// do
// int ans=count(s.begin(),s.end(),'y');



