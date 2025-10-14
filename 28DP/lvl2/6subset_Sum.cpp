// subset sum problem 
//Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1


// rec 
// likhne ka tarika 1.1
// int rec(vector<int>arr,int index,int sum,int currsum){
//         if(sum==currsum) return 1; // sum== currsum hogya toh return 1
//         if(currsum>sum) return 0;  // currsum > sum hogya toh return 0
//         if(index==arr.size()) return 0 ;   //sum==currsum ke baad likhege yeh index wali .... array khatm hogya par sum==currsum nhi hua toh return 0

//         // include
//         int include=rec(arr,index+1,sum,currsum+arr[index]);
//         // exclude
//         int exclude=rec(arr,index+1,sum,currsum);
        
//         return include||exclude ;
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
//         int index=0;
//         int currsum=0;
//         int ans=rec(arr,index,sum,currsum);
//         return ans;
//     }


// tc o(2^n) har element ke liye 2 option
// sc o(n)


// likhne ka tarika 1.2

// int rec(vector<int>arr,int index,int sum){
//         if(sum==0) return 1; 
//         if(sum<0) return 0;  
//         if(index==arr.size()) return 0 ;      

//         // include
//         int include=rec(arr,index+1,sum-arr[index]);
//         // exclude
//         int exclude=rec(arr,index+1,sum);
        
//         return include||exclude ;
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
//         int index=0;
//         int ans=rec(arr,index,sum);
//         return ans;
//     }

//likhne ka tarika 2  (better) at last


// mem

// int mem(vector<int>arr,int index,int sum, vector<vector<int> >&dp){
//         if(sum==0) return 1;
//         if(sum<0||index==arr.size()) return 0;

//         if(dp[index][sum]!=-1) return dp[index][sum]; 

//         // include
//         int include=mem(arr,index+1,sum-arr[index],dp);
//         // exclude
//         int exclude=mem(arr,index+1,sum,dp);
        
//         return dp[index][sum]=include||exclude ;
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
//         int n=arr.size();
//         int index=0;
//         vector<vector<int> >dp(n+1,vector<int>(sum+1,-1));
//         int ans=mem(arr,index,sum,dp);
//         return ans;
//     }


// tc o(n*sum)
// sc o(n*sum)+o(n)





// tabu

// int tabu(vector<int>arr,int sum){
//           int n=arr.size();
//         vector<vector<int> >dp(n+1,vector<int>(sum+1,-1));
      
//         for(int i=0;i<=n;i++){
//             dp[i][0]=1;
//         }
//         for(int j=1;j<=sum;j++){
//             dp[n][j]=0;
//         }
        
        
//        for(int index=n-1;index>=0;index--){
//            for(int j=1;j<=sum;j++){
               
//         // include
//         int include=0;
//         if(j>=arr[index]) include=dp[index+1][j-arr[index]];
//         // exclude
//         int exclude=dp[index+1][j];
        
//         dp[index][j]=include||exclude ;
//            }
           
//        }
        
//         return dp[0][sum];
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
    
//         int ans=tabu(arr,sum);
//         return ans;
//     }


// space opt

// int spaceopt(vector<int>arr,int sum){
//         int n=arr.size();
//         vector<int>next(sum+1,0);
//         vector<int>curr(sum+1,0);
//        next[0]=curr[0]=1;
        
//        for(int index=n-1;index>=0;index--){
//            for(int j=1;j<=sum;j++){
               
//         // include
//         int include=0;
//         if(j>=arr[index]) include=next[j-arr[index]];
//         // exclude
//         int exclude=next[j];
        
//         curr[j]=include||exclude ;
//            }
//            next=curr;
//        }
        
//         return next[sum];
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
    
//         int ans=spaceopt(arr,sum);
//         return ans;
//     }



// likhne ka tarika 2 (better)


// int rec(vector<int>arr,int index,int sum){
//         if(sum==0) return 1;   
//         if(index==arr.size()) return 0 ;      

//         // include
//         int include=0;
//         if(arr[index]<=sum)
//          include=rec(arr,index+1,sum-arr[index]);
//         // exclude
//         int exclude=rec(arr,index+1,sum);
        
//         return include||exclude ;
//     }


//     bool isSubsetSum(vector<int>arr, int sum){
//         int index=0;
//         int ans=rec(arr,index,sum);
//         return ans;
//     }