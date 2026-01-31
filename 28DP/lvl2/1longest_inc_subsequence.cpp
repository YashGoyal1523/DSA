// lc 300 longest increasing subsequence (lis)

// include/exclude

// class Solution {
// public:

//     int solveUsingRecursion(vector<int>& num, int curr, int prev) {
//        //base case
//        if(curr == num.size() ) {
//            return 0;
//        } 

// //  include
//     // if curr ki val>prev ki val then include curr wla 
//        int include = 0;
//        if(prev == -1 || num[curr] > num[prev] ) {   // prev  wali condition likhi for 0 index wale ko include k liye as voh wala compare wale m nhi aa payega as -1 wala not exist
//            include = 1 + solveUsingRecursion(num, curr+1, curr); // prev ko curr pe, curr ek aage
//        }
// // exclude
//        int exclude  = 0 + solveUsingRecursion(num, curr+1, prev); // prev vhi, curr ek aage

//        int ans = max(include, exclude);

//        return ans;
//     }

//    int lengthOfLIS(vector<int>& nums) {
//         int curr = 0; // index
//         int prev = -1; // index
//         int ans = solveUsingRecursion(nums,curr,prev);
//         return ans;
//     }
// };



// class Solution {
// public:

 
//     int solveUsingMem(vector<int>& num, int curr, int prev, vector<vector<int> >& dp) {
//        //base case
//        if(curr == num.size() ) {
//            return 0;
//        } 
//        //if ans already exists
//        if(dp[curr][prev+1] != -1 ) {    // index shifting krni padi prev mein ....as -1 bhi ho skta yeh and -1 index doesnt exist..+1 krlia......ab ek jagah dp ke col m +1 krdia toh jaha jaha dp aara ho uske col mein +1 krdena ...har jagah krna mat bhulna
//            return dp[curr][prev+1];   // // index shifting needed...+1
//        }

//        int include = 0;
//        if(prev == -1 || num[curr] > num[prev] ) { // idhar wale mein +1 ki need nhi as || ke baad h and prev -1 ka mtlb  phle wali true nikl gyi... toh yeh check hogi hi nhi seedha andar ghusegi
//            include = 1 + solveUsingMem(num, curr+1, curr,dp);
//        }
//        int exclude  = 0 + solveUsingMem(num, curr+1, prev,dp);    

//        dp[curr][prev+1] = max(include, exclude);     // index shifting needed...+1

//        return dp[curr][prev+1];   // index shifting needed...+1
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int curr = 0; // index
//         int prev = -1; // index
//         int n = nums.size();
//         vector<vector<int> > dp(n+1, vector<int>(n, -1)); // prev ke liye n liya as prev curr ke  piche hi hoga..worst case ek piche..vhi lege
//         int ans = solveUsingMem(nums,curr,prev,dp);
//         return ans;
//     }
// };




// class Solution {
// public:

//     int solveUsingTabulation(vector<int>& num ) {
//         int n = num.size();
//         vector<vector<int> > dp(n+1, vector<int>(n+1, 0)); //prev ka size n+1 lena pdega as...index shfting m n jaa skti value.... memoization m needed ni tha as vaha phle hi return hojata // initial initialistiaton handled

//         for(int curr_index=n-1; curr_index>=0; curr_index--) { // bade se chota flow// n handle krlia isiliye n-1
//             for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) { // bade se chota flow // starting wali value ke liye : prev curr ke  piche hi hoga..worst case ek piche..vhi lege

//                 int include = 0;
//                 if(prev_index == -1 || num[curr_index] > num[prev_index] ) { // idhar wale mein +1 ki need nhi as || ke baad h and prev -1 ka mtlb  phle wali true nikl gyi... toh yeh check hogi hi nhi seedha andar ghusegi
//                     include = 1 + dp[curr_index+1][curr_index+1]; //+1 krlia ....(jaha jaha dp aara har ke col mein +1 krna pdega)
//                 }
//                 int exclude  = 0 + dp[curr_index+1][prev_index+1];  // index shifting needed...+1
//                 dp[curr_index][prev_index+1] = max(include, exclude);    // index shifting needed...+1

//             }
//         }
//         return dp[0][0];   // index shifting needed ...+1 // dp[0][-1+1=0]; 
//     }
    
//   int lengthOfLIS(vector<int>& nums) {
//         int curr = 0; // index
//         int prev = -1; // index
//         int ans = solveUsingTabulation(nums);
//         return ans;
//     }
// };


// // ek row ka ans depend on next row

// class Solution {
// public:

//     int solveUsingTabulationSO(vector<int>& num ) {
//         int n = num.size();
//         vector<int> currRow(n+1, 0);
//         vector<int> nextRow(n+1, 0);


//         for(int curr_index=n-1; curr_index>=0; curr_index--) {
//             for(int prev_index=curr_index-1; prev_index >= -1; prev_index--) {

//                 int include = 0;
//                 if(prev_index == -1 || num[curr_index] > num[prev_index] ) { // idhar wale mein +1 ki need nhi as || ke baad h and prev -1 ka mtlb  phle wali true nikl gyi... toh yeh check hogi hi nhi seedha andar ghusegi
//                     include = 1 + nextRow[curr_index+1]; // +1 krlia (har dp m change krna)
//                 }
//                 int exclude  = 0 + nextRow[prev_index+1]; // index shifting needed...+1
//                 currRow[prev_index+1] = max(include, exclude); // index shifting needed...+1
//             }
//             //shifting
//             nextRow = currRow;
//         }
//         return nextRow[0]; // index shifting needed...+1
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int curr = 0; // index
//         int prev = -1; // index
//         int ans = solveUsingTabulationSO(nums);
//         return ans;
//     }
// };



//  USING BINARY SEARCH (more time and space optimised)
// class Solution {
// public:
   
//     int solveUsingBS(vector<int>& num ) {
//         vector<int> ans;
//         //initial state
//         ans.push_back(num[0]);  // increasing order bananeyeg isme

//         for(int i=1; i<num.size(); i++) {
//             if(num[i] > ans.back()) {
//                 ans.push_back(num[i]);
//             }
//             else {
//                 //just bada number exist krta hai
//                 int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
//                 //replace 
//                 ans[index] = num[i];
//             }
//         }
//         return ans.size();
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int ans = solveUsingBS(nums);
//         return ans;
//     }
// };


// // some variants of lis
// // agar ques hota ki find longest subsequence such that diff of adj is 1 -> sab same bas nums[curr]>nums[prev] use kiya vaha abs(nums[curr]-nums[prev])==1 krlo 
// // agar ques hota ki find longest subsequence such that diff of adj is k -> sab same bas nums[curr]>nums[prev] use kiya vaha abs(nums[curr]-nums[prev])==k krlo
// // agar ques ho ki bhot dabbe h and ek dabbe ko dusre par tbhi rkh skte ho jab uska wt dusre se kam ho , longest subsequence batao : longest decreasing subsequence case hogya -> sab same bas jaha nums[curr]>nums[prev]chalaya h vaha wt[curr]<wt[prev] krlo
// // increasing ya decreasing case m binary search lag jaayega

// // L Decreasing S
//  int solveUsingBS(std::vector<int>& num) {
//         std::vector<int> ans;
//         ans.push_back(num[0]);

//         for(int i = 1; i < num.size(); i++) {
//             if(num[i] < ans.back()) {
//                 ans.push_back(num[i]);
//             } else {
//                 int index = std::upper_bound(ans.begin(), ans.end(), num[i], std::greater<int>()) - ans.begin();
//                 ans[index] = num[i];
//             }
//         }
//         return ans.size();
//     }




// The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val. This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, lower_bound() returns the iterator of the first such value.
// The elements in the range shall already be sorted or at least partitioned with respect to val. 
// Syntax 1: 
// ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val); 
// Syntax 2: 
// ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp); 
 

// Parameters: The above methods accept the following parameters.  

// first, last: The range used is [first, last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
// val: Value of the lower bound to be searched for in the range.
// comp: Binary function that accepts two arguments (the first of the type pointed by ForwardIterator, and the second, always val), and returns a value convertible to bool. The function shall not modify any of its arguments. This can either be a function pointer or a function object.
// Return Value: An iterator to the lower bound of val in the range. If all the elements in the range compare less than val, the function returns last. If all the elements in the range are larger than val, the function returns a pointer to the first element. 


// upper_bound() is a standard library function in C++ defined in the header. It returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found. The elements in the range shall already be sorted or at least partitioned with respect to val.
// Syntax of upper_bound()
// The upper bound function have multiple signatures to fulfil the programmer’s requirements:

// upper_bound (first, last, val);
// upper_bound (first, last,  val, comp);
// Parameters
// first, last: The range used is [first, last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last. 
// val: Value of the upper bound to search for in the range. 
// comp: Binary function that accepts two arguments (the first of the type pointed by ForwardIterator, and the second, always val), and returns a value convertible to bool. The function shall not modify any of its arguments. This can either be a function pointer or a function object. 
// Return Value
// An iterator to the upper bound of val in the range. If all the element in the range compare less than val, the function returns last.




// STRIVER

// another tabulation method for length of lis

// class Solution {
// public:

// int longestIncreasingSubsequence(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> dp(n, 1);  // dp[i] signifies the length of longest inc subsequence from starting that ends at element present at i // initially sabpe 1 rkhge (uske longest subsequence m voh included h filhaal)
//     int maxi = -1; // for ans
//     for (int i = 0; i < n; i++)
//     {
//         for (int prev = 0; prev < i; prev++)
//         {
//             if (arr[prev] < arr[i])
//             {
//                 dp[i] = max(dp[i], 1 + dp[prev]);
//             }
//         }
//         maxi = max(maxi, dp[i]);
//     }
//     return maxi;
// }

// int lengthOfLIS(vector<int> &nums)
// {
//     int ans = longestIncreasingSubsequence(nums);
//     return ans;
// }
// };



// tc o(n^2)
// sc o(n)



//another variant of lis
//find lis such that bitwise and of sequence is not 0

//we know for the bitwise AND of a subsequence to be non-zero, there must be at least one bit position that is set (1) in every single number chosen for that subsequence.
//so approach is that
//ham har bit pos ke liye ans nikalege ie har bit pos ke liye lis nikalege jisme voh bit set ho and sabme se max lelege....
//har bit ke liye array ko filter krenge jaha vo bit set h yaani ek filtered array banalege jisme elements hoge jinme voh bit set hai and fir us filtered array pe lis lgayenge
// saari bit positions k liye krke sabme se max lenge



class Solution {
public:

        int LIS(vector<int>& num ) {
        vector<int> ans;
   
        ans.push_back(num[0]);  

        for(int i=1; i<num.size(); i++) {
            if(num[i] > ans.back()) {
                ans.push_back(num[i]);
            }
            else {
               
                int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
                
                ans[index] = num[i];
            }
        }
        return ans.size();
    }

    

    int longestSubsequence(vector<int>& nums) {
        int maxi = 0;
        
        for (int b = 0; b <= 31; ++b) {
            vector<int> newnums;
            for (int i=0;i<nums.size();i++) {
                int x=nums[i];
                if ((x >> b) & 1) {
                    newnums.push_back(x);
                }
            }           
            if (newnums.size()>0) {
                maxi = max(maxi,LIS(newnums));
            }
        }
        
        return maxi;
    }
};