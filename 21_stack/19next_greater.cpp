//next greater element

vector<int> next(vector<int>&v,int n){
    vector<int>ans(n);
    stack<int>st;
    st.push(-1); //-1 for no nge found
    for(int i=n-1;i>=0;i--){
        int curr=v[i];
        while(st.top()!=-1&&st.top()<=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
    
}


// next greater index

vector<int> next(vector<int>&v,int n){
    vector<int>ans(n);
    stack<int>st;
    st.push(-1); //-1 for no ngi found
    for(int i=n-1;i>=0;i--){
        int curr=v[i];
        while(st.top()!=-1&&v[st.top()]<=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    
}



//note:yeh bina -1 daale bhi kr skte


//next greater element

vector<int> next(vector<int>&v,int n){
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int curr=v[i];
        while(!st.empty()&&st.top()<=curr){
            st.pop();
        }
        ans[i]=st.empty()?-1:st.top();
        st.push(curr);
    }
    return ans;
    
}




// lc 739

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n);
    stack<int>st;
    st.push(-1); //-1 for no ngi found
    for(int i=n-1;i>=0;i--){
        int curr=temperatures[i];
        while(st.top()!=-1&&temperatures[st.top()]<=curr){
            st.pop();
        }
        if(st.top()==-1) ans[i]=0;
       else ans[i]=st.top()-i;
        st.push(i);
    }
    return ans;
    }
};