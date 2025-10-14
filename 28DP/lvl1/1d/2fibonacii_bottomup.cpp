// bottomup method (tabulation method)

// find f(n)


#include<iostream>
using namespace std ;

int tabu(int n){
     // 1. create dp array
    vector<int>dp(n+1,-1);               // note:dp array ke index recursion ke changing parameter banta h
    //2. analyse base case and fill initial dp array
    dp[0]=0;
    dp[1]=1;
    //3.fill remaining dp array using rec relation
    // remaining indexes ko bharege....index par loop chalao
    for (int index = 2; index <=n; index++)    //0,1 bhargye... 2 se bharna h       // note: loop ka flow recursion ke flow se ulta flow chalana hota....rec mein bade se chota jaara tha toh ya chote se bada krliya.......0,1 ka krliya toh 2 se shuru
    {
        dp[index]=dp[index-1]+dp[index-2];           
    }

    return dp[n];   //req ans is build up at n index ...return     // note:  recursion ke parameter ki initial value
}

int main()
{ int n;
    cin>>n;
    int ans=tabu(n);
    cout<<ans;

return 0;
}



// leetcode par agar issme runtime error aaye mtlb n=0 par fatra code as usme vector mein ek dabba banega par hum v[1] bhi access krre hoge toh dikkat krra voh... iske liye dp[0]=0 ke baad case daaldena if n==0 return dp[0] fir dp[1]=1 krna and aage sab 



// for loop in tabu mein flow -chote se bada jaana if recursion  m bade se chota jaara and bade se chota if usme chote se bada....recursion m jaha se jaha tak jaara(relevant values) yaha uska reverse krdo ..bas jo case already handle krliye  uske baad se chalna....like here rec mein n -n se 0 jaara toh loop mein 0 to n but 0,1 handled toh 2 se n

// tip: tab fn k liye ...mem wala dp array banao,rec base case se initial bharo,loop banao usme mem wala logic copy krro and fn ki jagah dp banao , return rec ke parameter ki initial value




//tip : kabhi memoization tle de...toh parameters ko by ref pass krke dekhna....solve hojaye toh thik hai vrna tabulation krna fir
// in practice, tabulation can be faster because:
// It uses loops instead of recursion
// No call stack overhead