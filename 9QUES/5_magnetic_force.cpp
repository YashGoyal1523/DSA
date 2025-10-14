// lc 1552
// similar to aggressive cow


// class Solution {
// public:

//     bool valid(vector<int>& position,int force,int ball ){
//         int n=position.size();
//         int lastball=position[0];
//         int ballcnt=1;
//         for(int i=1;i<n;i++){
//             if(position[i]-lastball>=force){
//                 ballcnt++;
//                 lastball=position[i];
//             }
//             if(ballcnt>=ball) return true;
//         }
//         return false;
//     }


//     int maxDistance(vector<int>& position, int m) {
//         sort(position.begin(),position.end());
//         int n=position.size();
//         int low=1;
//         int high=position[n-1]-position[0];
//         int ans;
//         while(low<=high){
//             int mid=(low+high)/2;
//             if(valid(position,mid,m)==true){    // check whether valid by checking can we place all balls
//                  ans=mid;
//                 low=mid+1;
//             }
//             else high=mid-1;
//         }
//         return ans;
        
//     }
// };