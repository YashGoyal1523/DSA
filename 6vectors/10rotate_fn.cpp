// rotate(first, middle, last);
// first: Iterator to the beginning of the range to rotate.
// middle: Iterator pointing to the new beginning of the range after rotation.
// last: Iterator to the end of the range ie next to last element
// The range [first, last) will be rotated so that the element pointed to by middle becomes the first element of the new range.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> vec ;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
//  {1, 2, 3, 4, 5}
    // Rotate elements to make '3' the first element
    rotate(vec.begin(), vec.begin() +2, vec.end());

    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}

//tips:
// If you want n left rotations , you can set the middle to first + n
// If you want n right rotations, you can set the middle to end - n 
