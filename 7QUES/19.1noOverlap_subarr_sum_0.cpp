// https://codeforces.com/contest/2033/problem/D


//count non overlapping subarrays sum 0

#include <iostream>
#include <unordered_map>
#include <vector>
#include<map>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 

        vector<int> arr(n); 

        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        map<long long, int> prefixSumCount; 
        long long currentPrefixSum = 0; 
        int Count = 0; 

        prefixSumCount[0] = 1; 

        
        for (int i = 0; i < arr.size(); i++) {
            currentPrefixSum += arr[i]; 

            
            if (prefixSumCount[currentPrefixSum]) {
                
                prefixSumCount.clear(); // non overlapping chahie toh reset
                prefixSumCount[0] = 1; 
                currentPrefixSum = 0; 
                Count++;
            }

            else
            prefixSumCount[currentPrefixSum]++;
        }

        
        cout << Count << endl;
    }

    return 0;
}