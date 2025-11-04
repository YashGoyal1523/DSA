// given an array, find kth smallest element 

// m1: sort then starting se kth uthalo ie arr[k-1] : tc o(nlogn) sc o(1)

//m2 : sab elements ka (min heap) min priority queue banado  fir k-1 times pop then top uthalo : tc o(nlogn) sc o(n)


// m3 : first k elements se ek (max heap) max priority queue banalo , for rem element : if element<top element -> top ko pop,element ko push in pq , sabke liye krne ke baad pq mein shuru ke k smallest elements present hoge, uska top element will be kth smallest element : tc o(nlogk) sc o(k)
int getKthSmallestElement(int arr[], int n, int k ) {
        //create max heap
        priority_queue<int> pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(arr[i]);
        }
        //for remaining elements , if element<top -> pop the top and push the element
        for(int i =k; i<n; i++) {
                int element = arr[i];
                if(element < pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;

}

// m3 ka alter...
// max heap m ek ek krke elements daalte jao and if size>k hojaye then pop (ie maintain maximum k elements in heap)...last m top element is ans : tc o(nlogk) sc o(k)