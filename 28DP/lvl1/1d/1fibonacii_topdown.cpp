// Dynamic Programming is a method used in mathematics and computer science to solve complex problems by breaking them down into simpler subproblems. By solving each subproblem only once and storing the results, it avoids redundant computations, leading to more efficient solutions for a wide range of problems. 

//find f(n)            0 1 1 2 3 5......



// RECURSION

// int recursion(int n ){
//     // base case
//     if(n==0) return 0;
//     if(n==1) return 1 ;


//     // recursive rel

//     int ans=recursion(n-1)+recursion(n-2);
    
//     return ans;

// }



// top down approach (rec+memoization aproach)

#include<iostream>
using namespace std ;

int rec_mem(int n,vector<int>&dp ){
    // base case
    if(n==0) return 0;
    if(n==1) return 1;

    //3.if ans already exist then return ans
    if(dp[n]!=-1){
        return dp[n];
    }

    // recursive 
    // 2.store and return using dp array

    dp[n]=rec_mem(n-1,dp)+rec_mem(n-2,dp);              // note: rec ke parameter wale variable ko index leke ...uspe storing and usko returning 
    return dp[n];  
    // // or
    // int ans=rec_mem(n-1,dp)+rec_mem(n-2,dp);             
    // dp[n]=ans;
    //  return dp[n];  
    // // or
    // int ans=rec_mem(n-1,dp)+rec_mem(n-2,dp);             
    //  return dp[n]=ans;  

}

int main()
{
    int n;
    cin>>n;

    // 1. create dp array
    vector<int>dp(n+1,-1);   //dp[i] stores the ans of i   //n+1 size ka lagega as then index n tak aayega         //note:dp array ke index recursion ke changing parameter ka banega 

    int ans=rec_mem(n,dp);

    cout<<ans<<endl; 

    for(auto i:dp){
    cout<<i<<" ";
    }

    
    return 0;
}


// important -> tc = no of states * transition time


// o(n) - har problem ek baar solve hori h   


// har ques mein same hi tarika lagega jse isme kiya hai


// dp array ke index recursion ke changing parameter ka banega

// dp array ka size ke liye dekho ki array ki index value kaha se kaha tak chahie
// recursion ke parameter ki input value and final base case value se dekh lena ki kaha se kaha tak vary hori..usi se index ki miljaygea.........(vse mem mein base case wale index ki value ki need nhi hoti as uska toh seedha return krte ans toh storing no need ....toh chaho toh base case se range banake and base case wala ignore kr skte (ending array ke side wala index h toh hi kr paayege...agar starting side wala h toh fir toh nhi hi kr skte )  . Tabu mein base case wale index ki bhi need hoti h 
// dp array ka size smjh na aaye toh bada sa rakh lo kuch  n+_ krke no dikkat

//tip: dp array create krne ke baad.... mem fn ke liye recursion wala fn as it is copy paste krke changes krlo ->  fn name change , dp pass in fn (by ref) , ans store and return using dp (rec ke parameter wale variable ko index leke uspe store and usko return), already exist wali condition add
