// m1:normal: if %2==0 then even ==1 then  odd

// m2 :bitwise method: if Lsb is 0 ie rightmost bit is 0 then no is even and if 1 then odd
#include <iostream>
using namespace std;

void checkEvenOdd(int n)
{
    if (n & 1)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even" << endl;
    }
}
int main()
{
    int n = 9;
    checkEvenOdd(n);
    return 0;
}