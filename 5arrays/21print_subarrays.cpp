//  (subarray: all possible adjacent element combinations ie continuous combinations , subsequence : all possible element combinations ) // empty is also subarray and subsequence
// eg for abc  -> subarray: a,b,c,ab,bc and subsequence : a,b,c,ab,,bc,ac
// no of subarrays =(n*(n+1))/2    n size
// no of subsequnece =2^n    n size


// printing all contigous(atleast 1 element present) subbarrrays

// using 3 for loops
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    // Iterate over all possible starting points of subarray
    for (int si = 0; si < n; si++)
    {
        // Iterate over all possible ending points of subarray
        for (int ei = si; ei < n; ei++)
        {
            // print subarray from index 'start' to 'end'
            for (int i = si; i <= ei; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

