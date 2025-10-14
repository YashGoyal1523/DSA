// The Painter's Partition Problem

//https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

//striver

// similar to book allocation

// isme ans always possible h as isme esa koi constraint nhi h ki sabko kaam dena ....toh no possible wala kuch na h as n<k m bhi ans h
// we need to minimise the max time taken by a painter
// time to paint a board=length of board
// max time one take can lie in [max of array,sum of array] 




// #include<bits/stdc++.h>
// int countPainters(vector<int> &boards, int time) {
//     int n = boards.size(); //size of array.
//     int painters = 1;
//     long long boardsPainter = 0;
//     for (int i = 0; i < n; i++) {
//         if (boardsPainter + boards[i] <= time) {
//             //allocate board to current painter
//             boardsPainter += boards[i];
//         }
//         else {
//             //allocate board to next painter
//             painters++;
//             boardsPainter = boards[i];
//         }
//     }
//     return painters;
// }

// int findLargestMinDistance(vector<int> &boards, int k) {
//     int low = *max_element(boards.begin(), boards.end());
//     int high = accumulate(boards.begin(), boards.end(), 0);
//     int ans=-1;
//     //Apply binary search:
//     while (low <= high) {
//         int mid = (low + high) / 2;
//         int painters = countPainters(boards, mid);
//         if (painters > k) {
//             low = mid + 1;
//         }
//         else {
//             ans=mid;
//             high = mid - 1;
//         }
//     }
//     return ans;
// }


// lakshay bhaiya ka soln:
// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1
// search space : [1,sum] (uper wala iss search space m nhi chalega)

// class Solution
// {
// public:
//     bool isPossibleSolution(int arr[], int n, int k, long long mid)
//     {
//         long long timeSum = 0;
//         int c = 1;
//         for (int i = 0; i < n; i++)
//         {
//             if (arr[i] > mid)
//             {
//                 return false;
//             }
//             if (arr[i] + timeSum > mid)
//             {
//                 c++;
//                 if (c > k) return false;
//                 timeSum = arr[i];
//             }
//             else
//             {
//                 timeSum += arr[i];
//             }
//         }
//         return true;
//     }

//     long long minTime(int arr[], int n, int k)

//     {
//         long long start = 1;

//         long long end = 0;
//         for (int i = 0; i < n; i++)
//         {
//             end += arr[i];
//         }
//         long long ans = -1;

//         while (start <= end)
//         {
//             long long mid = start + (end - start) / 2;
//             if (isPossibleSolution(arr, n, k, mid))      // check valid by checking whether can we allocate to <=k
//             {
//                 ans = mid;
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
//         }
//         return ans;
//     }
// };