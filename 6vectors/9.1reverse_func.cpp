#include<iostream>    //  reverse() function in c++........reverse(first pos,last pos):reverse the elements in range [first,last) ...last not included...........to reverse in range [start,end] ...do ....reverse(position of start , position of next to end) 
#include<vector>
using namespace std ;
int main()
{
// reversing array
int arr[5]={1,2,3,4,5};
    int n=5;  // no of elements...size
 
    // reversing full array
    reverse(arr,arr+n);         //arr will give position(address) of first element (index 0)... ......arr+(n-1) will givee position of last element ie n-1 index......+n will give next to last

    // to reverse from 2nd to 4th element ie index 1 to index 3
    reverse(arr+1,arr+4);




//reversing vector

vector<int>v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);


// reverse full
reverse(v.begin(),v.end());

// v.begin()  will give positioning (iterator) of first element ie index: 0
// v.end() will give positioning of next to last element 

//or
// reverse(v.begin(),v.begin()+v.size());


 // to reverse from 2nd to 4th element ie index 1 to index 3
reverse(v.begin()+1,v.begin()+4);

return 0;
}




// two pointer method se bhi reverse kar skte vector


// note:  (iterator at i index) - (iterator at 0 index) =  i   : can be used when hume koi iterator dediya and boldiya kisi index par h and find index...toh it-arr.begin() will give us index



// diff bw iterator and pointer - https://www.geeksforgeeks.org/difference-between-iterators-and-pointers-in-c-c-with-examples/