// lc 632 smallest range covering from k lists 

// sab arrays ka phle element uthao phle
// unse ek range milgyi [unka min,unka max]
// ab min wale mein aage bhado
// firse range milgyi [unka min , unka max]
// fir min wale mein shift and repeat
// ese ese krte jao jabtak koi array khatm hojaye ie min se aage shift hone m khatm hojaye
// sabhi ranges mein se min range is ans



class compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //min heap
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        int maxi = INT_MIN;
        //  first elements daaldo
        for (int i = 0; i < nums.size(); ++i) {
            int element = nums[i][0];
            int row = i;
            int col = 0;
            pq.push({element, row, col});
            maxi = max(maxi, element);
           
        }
    
            // phle elements dalgye 
            // phlo ka max pata chalgya

        // now

        int ansStart = -1e9;
        int ansEnd = 1e9;  // shuru mein badi range leli ek 

        while (1) {
         // min element
            auto topNode = pq.top();
            int topData = topNode[0];
            int topRow = topNode[1];
            int topCol = topNode[2];
            
            pq.pop();

            int mini = topData;

    // min milgya , max pata h    
    // range update   
            if ((maxi - mini) < (ansEnd - ansStart)) {
                ansStart = mini;
                ansEnd = maxi;
            }
    // next element push
            if (topCol + 1 < nums[topRow].size()) {
                int newElement = nums[topRow][topCol + 1];
                // maxi update
                maxi = max(maxi, newElement);
                pq.push({newElement, topRow, topCol + 1});
            }
             else { //element not present
                break;
            }
        }

        return {ansStart, ansEnd};
    }
};
