// count no of dearrangements possible

// dearrangement- permutation jisme koi apni original position par na ho


// it is given by no of ways for each element ka multiply


#include <iostream>
using namespace std;
int solve(int n)
{
    // base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // ek case hum solve baaki recursion
    // phle element ke liye n-1 ways baakio ko recursion dekhlega
    // baakio ke liye 2 cases hoge
    // : jis position par phle element ko leke jaare uss wale lement ko phle wali ki pos par lagana : iss case m remaining n-2 elements ko solve krna rhgya
    // : jis position par phle element ko leke jaare uss wale lement ko khi bhi lagana : iss case m remaining n-1 elements ko solve krna rhgya
    // int ans = (n - 1) * solve(n - 1) + (n-1) *solve(n - 2);
    int ans = (n - 1) * (solve(n - 1) + solve(n - 2));

    
    return ans;
}
int main()
{
    int n = 4;
    cout << solve(n) << endl;
    return 0;
}