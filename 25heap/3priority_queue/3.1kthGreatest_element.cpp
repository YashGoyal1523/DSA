// given an array, find kth greatest element 


// first k elements se ek (min heap) min priority queue banalo , for rem element : if element>top element -> top ko pop,element ko push in pq , sabke liye krne ke baad pq mein shuru ke k greatest elements present hoge, uska top element will be kth greatest element : tc o(nlogk) sc o(k)
int getKthGreatestElement(int arr[], int n, int k) {
        //create min heap
        priority_queue<int, vector<int>, greater<int> > pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(arr[i]);
        }
        //for remaining elements , if element>top -> pop the top and push the element
        for(int i =k; i<n; i++) {
                int element = arr[i];
                if(element > pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;
}

// alter...ek ek krke elements daalte jao min heap m ...if size>k hojaye then pop (maintain maximum k elements in heap)...last m top element is ans


//lc 215
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};

//lc 703
class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if (pq.size() > K) pq.pop();
        }
       
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */