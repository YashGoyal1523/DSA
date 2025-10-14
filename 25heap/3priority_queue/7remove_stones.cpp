// lc 1962


// at an instant max element uthao and operation krdo


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // maxheap
        priority_queue<int>pq;

        // heap m daaldo sab
        for(int i=0;i<piles.size();i++){
            int element=piles[i];
            pq.push(element);
        }
        // k times operaton do
        while(k--){
            int topElem=pq.top();
            pq.pop();
            topElem=topElem-floor(topElem/2);
            pq.push(topElem);
        }
        
        // now remaining
        int sum=0;
        while(!pq.empty()){
            int top=pq.top();
            sum+=top;
            pq.pop();
        }

        return sum;
    }
};