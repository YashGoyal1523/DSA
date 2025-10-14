//bucket sort

//used when we need to sort elements of array frequency wise

// we create a vector<vector<int>>
//index : i-> represent frequency value
//index value : arr[i] -> elements having frequency i



class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;

        // Step 1: Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets (index = frequency)
        int n = nums.size();
        vector<vector<int>> bucket(n + 1); // max frequency can be n (all elements same)
        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        // Step 3: Collect elements frequency-wise (low to high)
        vector<int> ans;
        for (int i = 1; i <=n; i++) {
            for (int num : bucket[i]) {
                for (int j = 0; j < i; j++) {   // push 'num' i times
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};

//tc o(n)

//note
//  for (int i = 1; i <=n; i++) {
//             for (int num : bucket[i]) {
//                 for (int j = 0; j < i; j++) {   // push 'num' i times
//                     ans.push_back(num);
//                 }
//             }
//         }
// Outer loop runs n times, but most buckets are empty.
// Middle loop iterates over unique elements (spread across buckets).
// Inner loop executes i times for each element in bucket i.
// -> the total number of push_back calls across all buckets = n (because we output every element exactly as many times as it appears).
// So this step = O(n), not O(n²).

// rest all steps are also o(n)

// => tc-o(n)



//note 
// if two numbers have same frequency, the smaller number comes first.
// then do final loops like this

// for (int i = 1; i <= n; i++) {
//     sort(bucket[i].begin(), bucket[i].end()); // break ties
//     for (int num : bucket[i]) {
//         for (int j = 0; j < i; j++) {
//             ans.push_back(num);
//         }
//     }
// }

//for this -> o(nlogn) worst case (all elements are distinct)

//so overall tc ->o(nlogn) worst case


//lc 347


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        //index = frequency
        //Value will be elements
        //bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n+1);
        
        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;
            
            bucket[freq].push_back(element);
        }
        
        //Pick k elements from right to left to find k max frequency elements
        vector<int> result;
        for(int i = n; i >= 0; i--) {
            
            if(bucket[i].size() == 0) continue;
            
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            
        }
        
        return result;
    }
};

//lc 1636

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        //index = frequency
        //Value will be elements
        //bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n+1);
        
        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;
            
            bucket[freq].push_back(element);
        }
        
        
        vector<int> result;
        for (int i = 1; i <= n; i++) {
    sort(bucket[i].begin(), bucket[i].end(),greater<int>()); // break ties
    for (int num : bucket[i]) {
        for (int j = 0; j < i; j++) {
            result.push_back(num);
        }
    }
}
        
        return result;
    }
};


