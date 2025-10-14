// mik ki playlist  
// https://youtube.com/playlist?list=PLpIkg8OmuX-K1qUIQToCllUO0UIKXt8dB&si=gkFPrbkXBM1qd-57



// basics 

//segment tree is implemented using array
// imp note : take size of segment tree array as 4*n and not 2*n-1 (n : size of arr)   as  seg tree is not neccessarily complete binary tree so node indexes can go beyond 2*n-2

//eg
//for range sum query


//building segment tree
//tc:o(n) (saari nodes visit)      sc:o(n)
 void buildSegmentTree(int i, int l, int r, vector<int>& segmentTree, int arr[]) {
        if(l == r) {
            segmentTree[i] = arr[l];
            return;
        }
        
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1, l, mid, segmentTree, arr);
        buildSegmentTree(2*i+2, mid+1, r, segmentTree, arr);
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];
    }


//updating segment tree for point update (one element of array updated )
//tc:o(logn) (height traverse krni)
  void updateSegmentTree(int idx,int val,int i, int l, int r, vector<int>& segmentTree) {
        if(l == r) {
            segmentTree[i] = val;
            return;
        }
        
        int mid = l + (r-l)/2;
        if(idx<=mid){ //left child
        updateSegmentTree(idx,val,2*i+1, l, mid, segmentTree);
        }
        else{ //right child
        updateSegmentTree(idx,val,2*i+2, mid+1, r, segmentTree);
        }
        segmentTree[i] = segmentTree[2*i + 1] + segmentTree[2*i + 2];

        return;
    }  


//handling query
//tc: o(logn) (worst case mein height traverse krni)
  int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segmentTree) {
        if(l > end || r < start) { //outside
            return 0;
        }
        
        if(l >= start && r <= end) { //total overlap
            return segmentTree[i];
        }
        
        //partial overlap
        int mid = l + (r-l)/2;
        return querySegmentTree(start, end, 2*i+1, l, mid, segmentTree) + 
               querySegmentTree(start, end, 2*i+2, mid+1, r, segmentTree);
    }   




//updating segment tree for range update ( elements of array in a range are updated )

//m1 : range ke har element ke liye point update wala seg tree update krdo : tc : o(nlogn)

//m2 :
// lazy propagation 


//T.C : O(logn) (worst case mein height traverse krni hogi)
//S.C : O(n)

//we have defined lazyTree[4*n] (intialised to zero)

void updateRange(int start, int end, int i, int l, int r, int val,vector<int>& segTree,vector<int>& lazyTree) {

    // Resolve any pending lazy value at this node 
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];
      
        if (l != r) { //Not a leaf node
            lazyTree[i * 2 + 1] += lazyTree[i]; 
            lazyTree[i * 2 + 2] += lazyTree[i]; 
        }
        lazyTree[i] = 0;
    }

    // outside
    if (l > end || r < start )
        return;

    // total overlap
    if (l >= start && r <= end) {
        segTree[i] += (r - l + 1) * val;
        if (l != r) {
            lazyTree[i * 2 + 1] += val;
            lazyTree[i * 2 + 2] += val;
        }
        return;
    }

    //partial overlap
    int mid = (l + r) / 2;
    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);

    segTree[i] = segTree[i * 2 + 1] + segTree[i * 2 + 2];

}

//modified handling query code to handle lazy propagation 

//tc : o(logn) (worst case mein height traverse krni hogi)
int querySegmentTree(int start, int end, int i, int l, int r, vector<int>& segTree,vector<int>& lazyTree){

    // Resolve any pending lazy value at this node 
    if (lazyTree[i] != 0) {
        segTree[i] += (r - l + 1) * lazyTree[i];

        if (l != r) {                 
            lazyTree[i * 2 + 1] += lazyTree[i];
            lazyTree[i * 2 + 2] += lazyTree[i];
        }
        lazyTree[i] = 0;             
    }

    //outside
    if (l > end || r < start) return 0;

    //total overlap
    if (l >= start && r <= end) return segTree[i];

    //partial overlap
    int mid = (l + r) / 2;
    return querySegmentTree(start, end, 2 * i + 1, l, mid, segTree, lazyTree) + 
           querySegmentTree(start, end, 2 * i + 2, mid + 1, r,segTree, lazyTree);
}


