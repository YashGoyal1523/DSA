// EKO

// https://www.spoj.com/problems/EKO/

// given sufficient wood hamesha milegi ie ans always possible

// now
// blade height [0,tallest tree ki height)  mein hi hame wood mil skti h.....so got search space ie [0,max of array)....... we want minimum wastage so shuru se last valid will be our ans

// shuru se start hoke last valid uthalo (linear)
// binary se krlo

// binary

#include <iostream>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for (long long int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            woodCollected += trees[i] - mid;
        }
    }
    return woodCollected >= m;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m)
{
    long long int start = 0, end=*max_element(trees.begin(), trees.end()), ans = -1;
   
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSolution(trees, m, mid))   // check valid ie checking if sufficient wood miljayegi
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout << maxSawBladeHeight(trees, m) << endl;
    return 0;
}
