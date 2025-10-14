// given an array of positive elements and +ve integer k. Find the total number of subarrays having bitwise XOR of all elements equal to k.

// https://youtu.be/eZr-6p0B7ME?si=tMIVgvhYpTst3u3_
//https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/


//bruteforce
// Time Complexity: O(N2), where N = size of the array.
#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); 
    int cnt = 0;

  
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            xorr = xorr ^ a[j];

            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}


//optimal

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array. Point to remember for unordered_map in the worst case, the searching time increases to O(N), and hence the overall time complexity increases to O(N2). 


//         X
//    -------------
//    4  2  2  6  4  5       
//    ----  -------                   x,k,X : xor values  =>  X - xor value till index i (index 0 to i), k - xor value of subarray ending at index i (subarray ranges in index [1,i] ), x- xor value of subarray from starting (subarray can be empty and ranges in index [0,i-1] )  
//     x       k

//      x^k = X  
// =>  x^k^k = X^k  (xor k both sides)
// =>  x= X^k

// for every X ie for each index count no of x present . sum of all cnt of x is ans


#include <iostream>
#include<map>
using namespace std;

int subarraysWithXorK(int a[], int k) {
    int n = 5; //size of the given array.
    map<int, int> mpp; 
    mpp[0]++;  // starting wala subarray as empty ke liye krdia
    int cnt = 0;
    int X = 0;
    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        X = X ^ a[i];

        //By formula: x = X^k:
        int x = X ^ k;

        // add the occurrence of X^k ie x  to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i into the map:
        mpp[X]++;
    }
    return cnt;
}

int main()
{
    int a[] = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
