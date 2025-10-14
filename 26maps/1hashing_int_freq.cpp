// striver

//ques- given array of integers ...tell frequency of a particular integer

// brute force- traverse and count++ krte jao


// another method : hashing ( hashing : keys ko uski value se map krna . hashtable is used . hashfunctions use krke keys ka hashindexes(indexes of hashtable) nikal lete  fir uss index par value store krlete)



// hashing using array as hash table :hash array/bucket array 

// we will be maintaining count of each integer in the array - integer value (keys) ka count (value) ...array ke indexes (hashindex) equal to value (hashfunction hai ki hashindex is equal to key ki value) par maintain krlege . 
#include<iostream>
using namespace std ;
int main()
{
int arr[5]={1,2,1,4,12};
int n=5;  // size of array

// precompute - 
//(hashindex is equal to key ki value)
int hash[13] = {0};//(given max value in array can be 12)  so 13 size ka banaliya taaki 12 index tak aajaye   // hash array  / bucket 
for(int i = 0;i<n;i++) {
hash[arr[i]]+= 1;        
}
// hamare paas har integer ki freq stored h ab
// fetch
int number;   // no. to be fetched 
cin >> number;

cout << hash[number] << endl;

return 0;
}



// counting sort - hashing using array se count of each maintain krlete .....fir hash array mein shuru se shuru hojate and jiski jitni values hai utne places usko ans array m shuru se shuru hoke dete jaate