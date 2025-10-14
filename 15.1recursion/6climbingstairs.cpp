// leetcode 70
//You are climbing a case. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 #include<iostream>
 using namespace std ;

int solve(int n){
    if(n==1) return 1;
    if(n==2) return 2;

    //nth step par (n-1)th se aaye hoge(1 step ) ya (n-2)th se aaye hoge (2 steps)...so n tak aane ke ways is (n-1)th tak aane ke no of ways  + (n-2)th tak aaane ke ways
    int ans=solve(n-1)+solve(n-2);
    return ans;

}


 int main()
 {
    int n;
    cout<<"enter number";
    cin>>n;
    int ans=solve(n);
    cout<<ans;
 return 0;
 }


 // this method will give TLE in leetcode