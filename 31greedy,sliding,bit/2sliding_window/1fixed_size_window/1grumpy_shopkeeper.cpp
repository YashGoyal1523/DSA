// fixed size window type
// sliding window size k fixed problems


// general approach-
// process first k elements(1st window) , process remaining windows by keep on adding front element and remove back element
// ek pointer se bhi kr skte and two pointer se bhi kr skte 





// lc 1052

// bruteforce 1
// shuru se shuru hoke minutes size block lo grumpy mein and uske elements ko  0 banao fir total 0 walo ke customers  add krlo... fir agla minutes block lo sabko 0 banao fir saare 0 waalo ko add kro ...ese ese last minute block tak kkrlo and sabka max lelo

// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         int i=0;
//         int j=minutes-1;
//         int ans=0;
//         while(j<grumpy.size()){
//             vector<int>temp(grumpy.size(),0);
//             temp=grumpy;
//             for(int x=i;x<=j;x++){
//                 temp[x]=0;
//             }
//             int cust=0;
//             for(int y=0;y<temp.size();y++){
//                 if(temp[y]==0){
//                     cust=cust+customers[y];
//                 }
//             }
//             ans=max(ans,cust);
//             i++;
//             j++;

//         }
//         return ans;
//     }
// };


// bruteforce 2

// ek baar bina trick ke nikalo...fir shuru se shuru hoke har individuak window ka extra nikalke add krte jao and max ans lete jao


// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
//         // satisfied cust without trick
//         int cust=0;
//         for(int i=0;i<grumpy.size();i++){
//             if(grumpy[i]==0){
//                 cust=cust+customers[i];
//             }
//         }
//         int ans=-1;
//         // with trick in each window  
//         for(int i=0;i<grumpy.size()-minutes+1;i++){     // outer windows
//             int x=i;
//             int extra=0;
//             for(int j=1;j<=minutes;j++){       // inner window
//                 if(grumpy[x]==1){
//                     extra=extra+customers[x];
//                     x++;                  
//                 }
//                 else x++;
//             }
//             int temp=cust+extra;
//             ans=max(ans,temp);

//         }
//         return ans;
//     }
// };



// sliding window concept
// using ek pointer

// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         int n = customers.size();
//         int totalSatisfied = 0;

//         // Calculate the number of customers satisfied without any secret technique
//         for (int i = 0; i < n; ++i) {
//             if (grumpy[i] == 0) {
//                 totalSatisfied += customers[i];
//             }
//         }

//         // Calculate the additional customers satisfied by using the secret technique in first window
//         int additionalSatisfied = 0;
//         for (int i = 0; i < minutes; ++i) {
//             if (grumpy[i] == 1) {
//                 additionalSatisfied += customers[i];
//             }
//         }

//         int maxAdditionalSatisfied = additionalSatisfied;

//         // Slide the window from start to end of the array
//         for (int i = minutes; i < n; ++i) {
//             // new add
//             if (grumpy[i] == 1) {
//                 additionalSatisfied += customers[i];
//             }
//             //out of range remove
//             if (grumpy[i - minutes] == 1) {
//                 additionalSatisfied -= customers[i - minutes];
//             }
//             maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
//         }

//         return totalSatisfied + maxAdditionalSatisfied;
//     }
// };

// sliding window wala using two pointer

// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
//         int n = customers.size();
//         int totalSatisfied = 0;

//         // Calculate the number of customers satisfied without any secret technique
//         for (int i = 0; i < n; ++i) {
//             if (grumpy[i] == 0) {
//                 totalSatisfied += customers[i];
//             }
//         }

//         int i=0;
//         int j=0;

//         // Calculate the additional customers satisfied by using the secret technique in first window
//         int additionalSatisfied = 0;
//         while(j<minutes){
//             if (grumpy[j] == 1) {
//                 additionalSatisfied += customers[j];
//             }
//             j++;
//         }

//         int maxAdditionalSatisfied = additionalSatisfied;

//         // Slide the window from start to end of the array
//        while(j<grumpy.size()){
//             // new add
//             if (grumpy[j] == 1) {
//                 additionalSatisfied += customers[j];
//             }
//             //out of range remove
//             if (grumpy[i] == 1) {
//                 additionalSatisfied -= customers[i];
//             }
//             maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
//             // window shift
//             i++;
//             j++;
            
//         }

//         return totalSatisfied + maxAdditionalSatisfied;
//     }
// };