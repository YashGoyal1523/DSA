// lc 650

// har step par we have two options - paste ya copy paste
// note first step m paste ke liye kuch nhi h toh copy paste hi krna pdega 



// m1: first step alag handle, baaki step alag se ek saath handle :not preffered 

// way 1

// class Solution {
// public:

//     void solve(int currlen,int cliplen,int operation,int n,int &ans){
//         if(currlen==n){
//             ans=operation;
//             return;
//         }

//         if(currlen>n){
//             return;
//         }
        


//         // 2 option 
//         // paste
    
//             solve(currlen+cliplen,cliplen,operation+1,n,ans);
//         // copy paste
//             solve(currlen+currlen,currlen,operation+2,n,ans);

//             return;
//     }


//     int minSteps(int n) {
//         if(n==1) return 0;
//     // shuru mein only option is copy paste
//     // ek copy paste krlia
//         int currlen=2;
//         int cliplen=1;
//         int operation=2;
//         int ans;
//         solve(currlen,cliplen,operation,n,ans);

//         return ans;
//     }
// };


// way 2

// class Solution {
// public:

//     int solve(int currlen,int cliplen,int n){
//         if(currlen==n){
//             return 0;
//         }
//         if(currlen>n){       // not needed 
//             return 1e9;        //1e9 (large no) krdia taaki  min lene m obvious hatjayega
//         }
   
//         // 2 option 
//         // paste 
//            int paste=1+ solve(currlen+cliplen,cliplen,n);
//         // copy paste
//            int cp=2+ solve(currlen+currlen,currlen,n);

//             return min(paste,cp);
//     }


//     int minSteps(int n) {
//         if(n==1) return 0;
//     // shuru mein only option is copy paste
//     // ek copy paste krliya
//         int currlen=2;
//         int cliplen=1;
//         int ans=2+solve(currlen,cliplen,n);
    
//         return ans;
//     }
// };




// m2 sab steps ek saath handle : Preffered

// way1

// class Solution {
// public:

//     void solve(int currlen,int cliplen,int operation,int n,int &ans){
//         if(currlen==n){
//             ans=operation;
//             return;
//         }

//         if(currlen>n){
//             return;
//         }
        
//         // 2 option 
//         // paste
//       if(cliplen>0)    // shuru mein nothing to paste hoga isiliye yeh lagana pada
//             solve(currlen+cliplen,cliplen,operation+1,n,ans);

//         // copy paste
//             solve(currlen+currlen,currlen,operation+2,n,ans);

//             return;
//     }


//     int minSteps(int n) {
//         int currlen=1;
//         int cliplen=0;
//         int operation=0;
//         int ans;
//         solve(currlen,cliplen,operation,n,ans);

//         return ans;
//     }
// };


//way 2


// class Solution {
// public:

//     int solve(int currlen,int cliplen,int n){
//         if(currlen==n){
//             return 0;
//         }
//         if(currlen>n){       // not needed 
//             return 1e9;        //1e9 krdia taaki  min lene m obvious hatjayega
//         }
   
//         // 2 option 
//         // paste 
//        int paste=1e9;    //1e9 liya as shuru  wale m paste wala option hi nhi toh isko obvious hatana h toh min m hatjayega
//           if(cliplen>0){
//          paste=1+ solve(currlen+cliplen,cliplen,n);
//           }
//         // copy paste
//           int cp=2+ solve(currlen+currlen,currlen,n);

//             return min(paste,cp);
//     }


//     int minSteps(int n) {
        
//         int currlen=1;
//         int cliplen=0;
//         int ans=solve(currlen,cliplen,n);
    
//         return ans;
//     }
// };