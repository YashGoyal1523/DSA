#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int n)
{
    int s = 0, e = n;
    int ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);  // integer part wala  lelo phle 
    int precision = 10; // jitne precision tak nikalna
    double step = 0.1;
    for (int i = 0; i < precision; ++i)   // precision times loop chalao
    {
        double j = sqrt;
        while (j * j <= n)
        {
            j += step;
        }
        sqrt = j-step;
        step /= 10;    // phle mein 0.1 fir 0.01 fir 0.01 and so on
    }
    return sqrt;
}

int main()
{
    int n = 63;
    
    cout << myPrecisionSqrt(n) << endl;
    return 0;
}
