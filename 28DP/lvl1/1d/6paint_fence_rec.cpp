// There is a fence with n posts, each post can be painted with one of the k colors.
// You have to paint all the posts such that no more than two adjacent fence posts have the same color.
// Return the total number of ways you can paint the fence.
// n and k are non-negative integers.


// observe:  ans of n fences = k for n=1
//                           = k+k*(k-1) for n=2
//                            =(ans of n-1 )*(k-1) + (ans of n-2 )*(k-1)  = (ans of n-1  + ans of n-2 )*(k-1)   for n>2  


// RECURSION
#include <iostream>
using namespace std;

    int solveUsingRecursion(int n, int k)
    {
        // base case
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return (k + k * (k - 1));
        }
        int ans = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
        return ans;
    }
    int main()
    {
        int n = 3;
        int k = 3;
        int ans = solveUsingRecursion(n, k);
        cout << "Ans: "<< ans << endl;
        return 0;
   
}
