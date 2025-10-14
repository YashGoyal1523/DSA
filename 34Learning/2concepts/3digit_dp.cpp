//https://youtube.com/playlist?list=PLps5s7uQvz8kSh36EwW4_o1Qqjfm2vA1r&si=Y0Gi6eSFsAF8k0mJ
//https://usaco.guide/gold/digit-dp?lang=cpp
// https://www.geeksforgeeks.org/digit-dp-introduction/


// Digit DP is a technique used to solve problems that asks you to find the number of integers within a range that satisfies some property based on the digits of the integers. 
// Typically, the ranges are between large integers (such as between 1 to 10^9 or 10^18) so looping through each integer and checking if it satisfies the given property is too slow.
// Digit DP uses the digits of the integers to quickly count the number of integers with the given property in the range of integers.

// approach : 
// normal explore all nos krege toh tle hoga
// recursive explore all nos (digitwise building no) mein dp lagadege
// Will use tight variable to stay bounded

//tight variable ->true : restricted , false : not restricted


// range: [0,r]

// tight variable : tight -> restricted to right : true -> i = 0 to r[idx] , false -> i= 0 to 9
// new tight : ntight = tight & (i==r[idx])


// range :[l,r]

// m1:one tight variable : tight -> restricted to right  : sol(l,r) = sol(0,r)-sol(0,l-1)

// m2:two tight variables : tightl -> restricted to left , tightr -> restricted to right 
// (note: tightl : restricted to left : true -> i= l[idx] to 9 , false -> i=0 to 9  ; tightr : restricted to right : true -> i= 0 to r[idx] , false -> i=0 to 9)  
//so
// tightl tightr -> false false -> i = 0 to 9 , false true -> i=0 to r[idx] , true false -> i= l[idx] to 9 , true true -> i= l[idx] to r[idx]
//new tight : ntightl = tightl & (i==l[idx]) , ntightr = tightr & (i==r[idx])
 



//eg
//cf ques

// https://codeforces.com/contest/2121/problem/E


// rec
//likhne ka tarika 1
#include <bits/stdc++.h>
using namespace std;



int solve(string &s,string &t ,int idx,int tightl,int tightr){
    if(idx==s.size()) return 0;
    
    char low= tightl?s[idx]:'0';
    char high=tightr?t[idx]:'9';
    
    int ans=1e9;
    for(char i=low;i<=high;i++){
        int cost=0;
        cost+=(i==s[idx]);
        cost+=(i==t[idx]);
        int ntightl=tightl&&(i==s[idx]);
        int ntightr=tightr&&(i==t[idx]);
        cost += solve(s,t,idx+1,ntightl,ntightr);
        ans=min(ans,cost);
    }
    
    return ans;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int l,r;cin>>l>>r;
	    
	    int tightl=1;
	    int tightr=1;
	    int idx=0;
	    
	    string s=to_string(l);
	     string t=to_string(r);
	     
	    
	    int ans=solve(s,t,idx,tightl,tightr);
	    
	    cout<<ans<<endl;
	}

}

//likhne ka tarika 2
#include <bits/stdc++.h>
using namespace std;



int solve(string &s,string &t ,int idx,int tightl,int tightr){
    if(idx==s.size()) return 0;
    
    int low= tightl?s[idx]-'0':0;
    int high=tightr?t[idx]-'0':9;
    
    int ans=1e9;
    for(int i=low;i<=high;i++){
        int cost=0;
        cost+=(i==s[idx]-'0');
        cost+=(i==t[idx]-'0');
        int ntightl=tightl&&(i==s[idx]-'0');
        int ntightr=tightr&&(i==t[idx]-'0');
        cost += solve(s,t,idx+1,ntightl,ntightr);
        ans=min(ans,cost);
    }
    
    return ans;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int l,r;cin>>l>>r;
	    
	    int tightl=1;
	    int tightr=1;
	    int idx=0;
	    
	    string s=to_string(l);
	     string t=to_string(r);
	     
	    
	    int ans=solve(s,t,idx,tightl,tightr);
	    
	    cout<<ans<<endl;
	}

}




//dp


#include <bits/stdc++.h>
using namespace std;



int solve(string &s,string &t ,int idx,int tightl,int tightr, vector<vector<vector<int>>>&dp){
    if(idx==s.size()) return 0;
    
    if(dp[idx][tightl][tightr]!=-1) return dp[idx][tightl][tightr];
    
    char low= tightl?s[idx]:'0';
    char high=tightr?t[idx]:'9';
    
    int ans=1e9;
    for(char i=low;i<=high;i++){
        int cost=0;
        cost+=(i==s[idx]);
        cost+=(i==t[idx]);
        int ntightl=tightl&&(i==s[idx]);
        int ntightr=tightr&&(i==t[idx]);
        cost += solve(s,t,idx+1,ntightl,ntightr,dp);
        ans=min(ans,cost);
    }
    
    return dp[idx][tightl][tightr]=ans;
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    int l,r;cin>>l>>r;
	    
	    int tightl=1;
	    int tightr=1;
	    int idx=0;
	  
	    
	    string s=to_string(l);
	     string t=to_string(r);
	       int n=s.size();
	     
	     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
	    
	    int ans=solve(s,t,idx,tightl,tightr,dp);
	    
	    cout<<ans<<endl;
	}

}
