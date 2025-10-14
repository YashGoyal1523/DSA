//The pow() function in C++ calculates powers using floating-point arithmetic (double)
//returns a double result.
//The calculation of  2^i involves intermediate operations (e.g., logarithms, multiplications) that can introduce small errors due to finite precision.
// pow(2, 30) might return 1073741824.000001 instead of 1073741824.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double result = pow(2, 30);
    cout << "pow(2, 30) as double: " << result << endl;
    int converted = result;
    cout << "Converted to int: " << converted << endl;
    return 0;
}