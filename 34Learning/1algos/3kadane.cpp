//max subarray sum / min subarray sum / max product subarray 

//max subarray sum

//lc 53

// given array ...return max sum of contingous(atleast 1 element present) subarrays 


// m1: bruteforce : saare subarrays ko check 

//  teen for loop se  : o(n^3)

// int maxSubArraySum(vector<int>& nums) {
//     int maxSum = INT_MIN;
//     int n = nums.size();

//     // Iterate over all possible starting points of subarray
//     for (int start = 0; start < n; ++start) {
//         // Iterate over all possible ending points of subarray
//         for (int end = start; end < n; ++end) {
//             int currentSum = 0;
//             // Calculate sum of subarray from index 'start' to 'end'
//             for (int k = start; k <= end; ++k) {
//                 currentSum += nums[k];
//             }
//             // Update maxSum if current sum is greater
//             if (currentSum > maxSum) {
//                 maxSum = currentSum;
//             }
//         }
//     }

//     return maxSum;
// }


//  thoda optimise :  o(n^2)

// int maxSubArraySum(vector<int>& nums) {
//     int maxSum = INT_MIN;
//     int n = nums.size();

//     // Iterate over all subarrays
//     for (int i = 0; i < n; ++i) {
//         int currentSum = 0;
//         for (int j = i; j < n; ++j) {
//             currentSum += nums[j];
//             if (currentSum > maxSum) {
//                 maxSum = currentSum;
//             }
//         }
//     }

//     return maxSum;
// }





// m2 : kadane's algo  : o(n)

// tarika 1
// starting se shuru hoke.... elements ka sum krte jao ......har step pe max sum maintain krte jao .......jaha neg sum hojaye ... uske baad se sum nye se ie 0 se add krna shuru kro (as abtak ka sum -ve hogya toh isko aage include krne mein total sum kam hi hoga   )..... ..... end tak krlo

// int maxSubArray(vector<int>& nums) {
// int sum = 0;
// int maxi = INT_MIN;      
// for(int i=0; i<nums.size(); i++) {
// sum = sum + nums[i];
// maxi = max(maxi, sum); // ya likhlo  if(sum>maxi) {maxi=sum;}
// if(sum < 0) sum = 0; //phle maxi maintain krlena fir yeh krna dhyaan rkhnaa     // agar sum -ve bangya toh nye se shuruaat kro as neg add krne par toh kam hi hoga 
// }

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;


// return maxi;
// }




// to also print the subarray with greatest sum in m3


// int maxSubArray(vector<int>& nums) {
// int sum = 0;
// int maxi = INT_MIN;      
//  int start = 0;
// int ansStart = -1, ansEnd = -1;
// for(int i=0; i<nums.size(); i++) {
//   if (sum == 0) start = i; // starting index

//         sum += nums[i];

//         if (sum > maxi) {
//             maxi = sum;

//             ansStart = start;
//             ansEnd = i;
//         }

//         if (sum < 0) {
//             sum = 0;
//         }
//     }
// //printing the subarray:
//     cout << "The subarray is: [";
//     for (int i = ansStart; i <= ansEnd; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << "]";

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;

//     return maxi;
// }





//tarika 2
// For each element, decide:
// Should I start a new subarray at this element?
// Or extend the previous subarray?


int maxSubarraySum(vector<int>& nums) {
    int currentMax = 0;
    int overallMax = -1e9;

    for (int i = 0; i < nums.size(); i++) {
        currentMax = max(nums[i], currentMax + nums[i]);
        overallMax = max(overallMax, currentMax);
    }

    return overallMax;
}



// min subarray sum

//kadane

//tarika 1
int minSubArray(vector<int>& nums) {
    int sum = 0;
    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        mini = min(mini, sum);          // Update minimum sum so far
        if (sum > 0) sum = 0;    //min mainatain ke bad krna yeh step..dhyaan rkhna     // Reset sum if it becomes positive
    }

    // If you want to consider empty subarray with sum = 0 (optional):
    // if (mini > 0) mini = 0;

    return mini;
}


//tarika 2

int minSubarraySum(vector<int>& nums) {
    int currentMin = 0;
    int overallMin = 1e9;

    for (int i = 0; i < nums.size(); i++) {
        currentMin = min(nums[i], currentMin + nums[i]);
        overallMin = min(overallMin, currentMin);
    }

    return overallMin;
}



//max product subbarray

// lc 152

//bruteforce : teen for loop

//thoda optimise : do for loop

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi=INT_MIN;
//        for(int i=0;i<nums.size();i++){
//         int product=1;
//         for(int j=i;j<nums.size();j++){
//             product*=nums[j];
//             maxi=max(product,maxi);
//         }
//        }
//         return maxi;
//     }
// };


// kadane algo 
// product lete jao .....max maintain krte jao....jaha zero banjaye vaha reset krdo ....
// ek baar left se shuru hoke aage jaana , ek baar right se shuru hoke piche aana...dono m se max lena
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int maxi=INT_MIN;
//         int product=1;
//         //left to right
//         for(int i=0;i<nums.size();i++){
//             product*=nums[i];
//             maxi=max(product,maxi);
//             if(product==0) product=1;
//         }

//         product=1;

//         // right to left
//         for(int i=nums.size()-1;i>=0;i--){
//             product*=nums[i];
//             maxi=max(product,maxi);
//             if(product==0) product=1;
//         }

//         return maxi;
//     }
// };