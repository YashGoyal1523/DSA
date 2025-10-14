// lc624

 // sabme se max element - sabme se min element krege
 // par note
 // dono element alag alag array se hoge ...toh
 // min max ek array se nhi ho skte and alag alag se hoge..
  
 // arrays sorted h toh min wala sabke starting element se dhudna hoga and max wala sabke ending element se dhudna hoga
 


// m1

 // do case banege
 // sabme se phle min dhundlo fir min wale array ko ignore krke max dhundlo and diff lelo
 // sabme se phle max dhundlo fir max wale row ko ignore krke min dhundlo and diff lelo
 // dono ke diff ka max lelo



// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
      
//         // phle min dhundna fir max dhundna
//         int mini1=INT_MAX;
//         int minirow=-1;
//         for(int i=0;i<arrays.size();i++){
//             if(arrays[i][0]<mini1){
//                 minirow=i;
//                 mini1=arrays[i][0];
//             }
//         }
//         int maxi1=INT_MIN;
//         for(int i=0;i<arrays.size();i++){
//             if(i!=minirow && arrays[i][arrays[i].size()-1]>maxi1){
//                 maxi1=arrays[i][arrays[i].size()-1];
//             }
            
//         }
//     // phle max dhundna fir min dhundna
//     int maxi2=INT_MIN;
//         int maxirow=-1;
//         for(int i=0;i<arrays.size();i++){
//             if(arrays[i][arrays[i].size()-1]>maxi2){
//                 maxirow=i;
//                 maxi2=arrays[i][arrays[i].size()-1];
//             }
//         }
//         int mini2=INT_MAX;
//         for(int i=0;i<arrays.size();i++){
//             if(i!=maxirow && arrays[i][0]<mini2){
//                 mini2=arrays[i][0];
//             }
            
//         }

//         return max(maxi1-mini1,maxi2-mini2);
//     }
// };



// m2  greedy 

// intution-ek ek krke har array pe aao and ans=max( curr_se_phle_ka_max - curr_array_starting , curr_array_ending - curr_se_phle_ka_min) krte jao 
// algo-starting m phla array lo and uska starting element min_element banado and ending element max_eleemnt banado fir aage  array pe aao and ans nikaldo using this min max element and curr array starting ending element and ans nikalne ke baad yeh dono update krdo -> min_element=min(mini_element,curr_array_starting) , max_element=max(max_element,curr_array_ending) ...fir aage next array pe aao and repeat ...sabpe krlo


// class Solution {
// public:
//     int maxDistance(vector<vector<int>>& arrays) {
//         int ans=0;
//         int min_val=arrays[0].front();
//         int max_val=arrays[0].back();
//         for(int i=1;i<arrays.size();i++){
//             ans=max(ans,max(max_val-arrays[i].front(),arrays[i].back()-min_val));
//             min_val=min(min_val,arrays[i].front());
//             max_val=max(max_val,arrays[i].back());
//         }
//         return ans;
//     }
// };