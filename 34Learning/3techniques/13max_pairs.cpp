// given an array of integers . find max no of pairs of different valued elements that can be formed

//eg [1,2,3,4] -> ans=2 : (1,2),(3,4)
// eg [2,2,1,3] -> ans=2 : (2,1),(2,3)
//eg [2,2,1] -> ans=1 : (2,1)
//eg [2,2] -> ans=0

// approach 

// let x be the frequency of max freq element and n be total elements

// if x>n-x // x>n/2
// pairs=n-x
// else 
//pairs = n/2
//or 
//pairs = min(n/2,n-x)

//note: no of left unpaired=n-2*pairs 



//lc 3664

// https://www.youtube.com/live/BzChniR00vE?si=lldjLMwfnyUzCT-O

class Solution {
public:
    int score(vector<string>& cards, char x) {
        int n = 0, m = 0, k = 0;  
        // n = count of type I (1st pos is x), m = count of type II(2nd pos is x), k = count of type III(both pos is x)

        map<char, int> a, b;  
        // a → frequency map of type I (cards starting with x)
        // b → frequency map of type II (cards ending with x)

        for (auto &card : cards) {
            if (card[0] == x && card[1] == x) {
                k++;  // type III (both sides are x)
            } else if (card[0] == x) {
                a[card[1]]++;  
                n++;  // type I
            } else if (card[1] == x) {
                b[card[0]]++;  
                m++;  // type II
            }
        }

        int a_max = 0, b_max = 0; // max freq in type 1 and type 2
        for (auto &[ch, cnt] : a) a_max = max(a_max, cnt);
        for (auto &[ch, cnt] : b) b_max = max(b_max, cnt);

        int pair1 = 0, pair2 = 0, unpaired = 0;

        // type I pairs
        pair1 = min(n/2, n - a_max);
        unpaired += n - 2 * pair1;

        // type II pairs
        pair2 = min(m/2, m - b_max);
        unpaired += m - 2 * pair2;

        //use type 3 cards on unpaired of type 1 and type 2 

        //preliminary ans
        int ans = pair1 + pair2 + min(unpaired, k); 

        // use remaining type III cards to split type 1  and type 2 pairs
        if (k > unpaired) {
            ans += min(pair1 + pair2, (k - unpaired) / 2);
        }

        return ans;
    }
};
