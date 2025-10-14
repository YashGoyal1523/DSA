#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr[5];  // Array of 5 vectors

    vector<int> v(2,1);  // A vector v with some integers

    // Assigning vector v to arr[0]
    arr[0] = v;

    // Adding values to the first vector (arr[0])
    arr[0].push_back(1);
    arr[0].push_back(2);
    
    // Adding values to the second vector (arr[1])
    arr[1].push_back(3);
    
    // Accessing and printing values
    for (int i = 0; i < arr[0].size(); i++) {
        std::cout << "arr[0][" << i << "] = " << arr[0][i] << std::endl;
    }
    
    for (int i = 0; i < arr[1].size(); i++) {
        std::cout << "arr[1][" << i << "] = " << arr[1][i] << std::endl;
    }

    return 0;
}
