// paint fence // https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

// There is a fence with n posts, each post can be painted with one of the k colors.
// You have to paint all the posts such that no more than two adjacent fence posts have the same color.
// Return the total number of ways you can paint the fence.
// n and k are non-negative integers.


// observe:  ans of n fences = k for n=1
//                           = k+k*(k-1) for n=2   (same+diff)
//                            =(ans of n-1 )*(k-1) + (ans of n-2 )*(k-1)    (same + diff )   = (ans of n-1  + ans of n-2 )*(k-1)   for n>2  


#include <iostream>
using namespace std;

    int solve(int n, int k)
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
        int ans = (solve(n - 1, k) + solve(n - 2, k)) * (k - 1);
        return ans;
    }
    int main()
    {
        int n = 3;
        int k = 3;
        int ans = solve(n, k);
        cout << "Ans: "<< ans << endl;
        return 0;
   
}


