// given sorted array ...tell index if present and if not present then index where it should be prsent
#include<iostream>
using namespace std ;

int find_index(int arr[], int n, int K)
{
    // Traverse the array
    for (int i = 0; i < n; i++){
        // check current element

        if (arr[i] == K) // milgya
            return i;
        
        else if (arr[i] > K)// nhi mila and if current element exceeds K...then it means k isnt present in array...... and this current element position only is its appropriate position
            return i;
    }
    // yaha pahuch gye ....mtlb k nhi mila and usse koi bada bhi nhi mila so k is not present and koi usse bada bhi nhi hai yaani last mein hi aayega
    return n;
}
 

int main()
{
    int arr[] = { 1, 3, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;
    cout << find_index(arr, n, K) << endl;
    return 0;
}
 