//lc 77

//take/nottake

class Solution {
public:


    void solve(int &n,int k,int i,vector<int>temp,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i==n+1) return;

        //take
        temp.push_back(i);
        solve(n,k-1,i+1,temp,ans);
        temp.pop_back();

        //nottake
        solve(n,k,i+1,temp,ans);

    return;
    }



    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=1;
        solve(n,k,i,temp,ans);
        return ans;
    }
};


// mle degaa
// temp ko by ref leleo


class Solution {
public:


    void solve(int &n,int k,int i,vector<int>&temp,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i==n+1) return;

        //take
        temp.push_back(i);
        solve(n,k-1,i+1,temp,ans);
        temp.pop_back();

        //nottake
        solve(n,k,i+1,temp,ans);

    return;
    }



    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        int i=1;
        solve(n,k,i,temp,ans);
        return ans;
    }
};