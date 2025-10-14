
//leetcode 113  path sum 2


// void solve(TreeNode* root, int targetSum, vector<int>temp, vector<vector<int> >&ans,int sum){ // temp by val and ans by ref hoga
//     if(root==NULL){
//         return ;
//     }

//     temp.push_back(root->val);
//     sum=sum+root->val;

//     if(root->left==NULL && root->right==NULL){
//         if(sum==targetSum){
//         ans.push_back(temp);
//         }
//         return;
//     }
   
//     solve(root->left,targetSum,temp,ans,sum);
//     solve(root->right,targetSum,temp,ans,sum);
   
//     return;
// }

// class Solution {
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int> >ans;
//         vector<int>temp;
//         int sum=0;
//         solve(root,targetSum,temp,ans,sum);
//         return ans;
//     }
// };