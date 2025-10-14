#include <iostream>
using namespace std;

int SO(int n, int k)
{

    int prev2 = k;  //initial represnt 1 index
    int prev1 = k + k * (k - 1);  //2 index
    if (n == 1)
    {
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }                     // yeh likhne pdege alag se
    int curr;
    for (int i = 3; i <= n; i++)
    {
        curr = (prev1 + prev2) * (k - 1);
        // shift
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main()
{
    int n = 5;
    int k = 3;
    int ans = SO(n, k);
    cout << ans;
    return 0;
}