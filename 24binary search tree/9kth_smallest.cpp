// lc 230
// kth smallest element in a bst

// inorder traversal mein kth lelo

// inorder ek array m store krke ...shuru se kth nikal lo
// bina store kre direct traverse krne m bhi krlege
// direct wla krte

// way1
// class Solution {
// public:

//     void solve(TreeNode* root ,int &k,int &ans){   // k by ref 
//         if(root==NULL){
//             return;
//         }

//     // L
//     solve(root->left,k,ans);
//     // N
//       k--;
//         if(k==0){
//             ans=root->val;
//             return;
//         }
//     // R
//     solve(root->right,k,ans);

//  return;
//     }

//     int kthSmallest(TreeNode* root, int k) {
//         int ans;
//         solve(root,k,ans);
//         return ans;
//     }
// };



// //way2
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int &k) {
//         if(root == NULL) {
//             return -1;
//         }
//         //LNR
//         //L
//         int leftAns = kthSmallest(root->left, k );
//         if(leftAns != -1) {
//             return leftAns;
//         }
//         //N;
//         k--;
//         if( k == 0) {
//             return root->val;
//         }
//         //R
//         int rightAns = kthSmallest(root->right, k);
//         return rightAns;
        
//     }
// };