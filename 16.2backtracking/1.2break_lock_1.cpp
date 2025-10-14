

// lc 3376

// try all orderings of breaking and sabme se min time uthalo

class Solution {
public:
    int  findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(),strength.end());
        int anstime=1e9;
        int time=0;
        int n=0;
       do {
        for(int i=0;i<strength.size();i++){
           int energyGeneratedPerSec=1+n*K;  // n ki jagah i hi use krlo seedha
           time+=(strength[i]+energyGeneratedPerSec-1)/energyGeneratedPerSec ; // ceil value
           n++;
        }
           anstime=min(anstime,time);
           time=0;
           n=0;
           
    } while (next_permutation(strength.begin(), strength.end()));

        return anstime;
    }
};