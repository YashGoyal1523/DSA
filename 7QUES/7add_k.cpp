// lc 989

// The array-form of an integer num is an array representing its digits in left to right order.
// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.


// answer

// note: pichla method(add 1 wala)(1 ki jaga k lelo bas) works in cases jab  carry is not of more than 1 digit and not when it is >1 as isme fir last wala carry dikkat dega as ek index par >1 digits hojayega
// note for k :single digit koi dikkat nhi aayegi (carry single digit hi rhega as do single digits ke sum m carry single digit hi rhega)...but for more aa skti
// eg if case is number is 0 and k is 100 then pichla method (1 ki jaga k lelo bas) will not work...eg num is 1 and k is 99....it will not work


// method which works for all ...sab case sambhaljayege ...carry single double more sab


// method 1 : pichle method m hi last wala carry ko digitwise lelo
// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//             vector<int>ans;
//         reverse(num.begin(),num.end());
//         int i=0;
//         int carry=k; // intial carry m k leliya  instead of 0 taaki aage wale code m k add ki dikkat na ho as yeh sirf ek baari hi hoga for first element and baakio m sirf carry and element hoga th voh ek baari wala initial carry m daaldiya
//         while(i<num.size()){
//             int sum=num[i]+carry;
//             int digit=sum%10;
//             carry=sum/10;
//             ans.push_back(digit);
//             i++;
//         }
//         // agar carry zero nhi hua toh daaldo...note kya pata 1 se zyada digits ho toh digit wise daalo
//         while(carry!=0){
//              ans.push_back(carry%10);
//              carry=carry/10;
//         }
//         // abhi ulta ans stored hai
//         reverse(ans.begin(),ans.end());

//         return ans;
//     }
// };


//method 2 : k ko bhi digitwise leke solve krlo ( 2 ya 3 single digits ke sum mein carry single digit hi rhega hmesha )

// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
       
//         vector<int>ans;
//         reverse(num.begin(),num.end());
//         int i=0;
//         int carry=0; 
// //  dono ke digits ek saath process
//         while(i<num.size()&&k>0){
//             int sum=num[i]+carry+k%10;
//             int digit=sum%10;
//             carry=sum/10;
//             ans.push_back(digit);
//             i++;
//             k=k/10;
//         }
//     // agar num khatm but k nhi khatm
//  while(k>0){
//             int sum=carry+k%10;
//             int digit=sum%10;
//             carry=sum/10;
//             ans.push_back(digit);
//             k=k/10;
//         }
// // agar k khatm but num nhi khatm
// while(i<num.size()){
//             int sum=carry+num[i];
//             int digit=sum%10;
//             carry=sum/10;
//             ans.push_back(digit);
//             i++;
//         }
//         // agar carry zero nhi hua toh daaldo     (dono digitwise mein single digit hi hoga carry chill)
//         if(carry!=0){
//              ans.push_back(carry);
//         }
//         // abhi ulta ans stored hai
//         reverse(ans.begin(),ans.end());

//         return ans;
//     }
// };