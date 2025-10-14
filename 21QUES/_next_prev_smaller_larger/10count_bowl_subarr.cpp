//c 3676


// har element ko bowl ka min wala end point banake dekho kitne bowl banara voh and sabko sum lelo
//ek element can serve as the smaller endpoint of at most two bowls : ek jab voh left endpoint ho and ek jab voh right end point ho
//to check for bowl ... we will find the other end point
//left point maanre -> find first greater or equal element to right.... this will be the other end point... if the subarray size >=3 count it
//similary... right point maanre -> prev greater or equal dekho
// use next greater prev greater concept of stack for implementation


class Solution {
public:
    vector<int>solve1(vector<int>& v){
        int n=v.size();
    vector<int>next(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int curr=v[i];
        while(!st.empty()&&v[st.top()]<=curr){
            st.pop();
        }
        next[i]=st.empty()?i:st.top();
        st.push(i);
    }
          return next;  
    }

 vector<int>solve2(vector<int>& v){
        int n=v.size();
    stack<int>st;
     vector<int>prev(n);
    for(int i=0;i<n;i++){
        int curr=v[i];
        while(!st.empty()&&v[st.top()]<=curr){
            st.pop();
        }
        prev[i]=st.empty()?i:st.top();
        st.push(i);
    }
return prev;
 }
    
    long long bowlSubarrays(vector<int>& v) {
        int n=v.size();
        vector<int>next=solve1(v);
        vector<int>prev=solve2(v);
 
    long long cnt=0;
        for(int i=0;i<n;i++){
            int p=prev[i];
            int n=next[i];
            if(n-i+1>=3) cnt++;
            if(i-p+1>=3) cnt++;
        }


    return cnt;
            
    }
};