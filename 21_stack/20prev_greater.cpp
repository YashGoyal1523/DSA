//prev greater index

vector<int> prev(vector<int>&v,int n){
    vector<int>ans(n);
    stack<int>st;
    st.push(-1); //-1 for no pgi found
    for(int i=0;i<n;i++){
        int curr=v[i];
        while(st.top()!=-1&&v[st.top()]<=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
     
}
