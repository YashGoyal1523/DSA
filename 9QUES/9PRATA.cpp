// PRATA

// https://www.spoj.com/problems/PRATA/

// max time to complete order will be jab highest rank wala saare banaye
// hume min time nikalna
// hum kya krege ki  [0,time jab highest wala sab banaye] search space mein starting se phla valid dhundlege

// linear se kr skte

// binary se krte

#include <iostream>
using namespace std;

bool isPossibleSolution(vector<int> cooksRanks, int np, int mid)
{
    int currp = 0; // initial cooked Prata Count
    for (int i = 0; i < cooksRanks.size(); i++)
    {
        int R = cooksRanks[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + j * R <= mid)
            {
                ++currp;
                timeTaken += j * R;
                ++j;
            }
            else
            {
                break;
            }
        }
        if (currp >= np)
        {
            return true;
        }
    }
    return false;
}

int minTimeToCompleteOrder(vector<int> cooksRanks, int nP)
{
    int start = 0;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (nP * (nP + 1) / 2);
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) >> 1;
        if (isPossibleSolution(cooksRanks, nP, mid))   // checking valid ie checking ki itne m parathe ban jaayege ya nhi
        {             // agar itne m banjayege toh iske right m bhi banhi jayege par hume min chahie toh ek baar isko store krke left dekho
            ans = mid; 
            end = mid - 1;
        }

        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int nP, nC;
        cin >> nP >> nC;
        vector<int> cooksRanks;
        while (nC--)
        {
            int R;
            cin >> R;
            cooksRanks.push_back(R);
        }
        cout << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    }
    return 0;
}