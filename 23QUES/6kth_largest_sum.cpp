// lc 2583 
//Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// vector<long long> levelOrderTraversal(TreeNode* root){
//     vector<long long>v;
//     queue<TreeNode*>q;
//     long long sum=0;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         TreeNode* node=q.front();
//         q.pop();
//         if(node!=NULL){
//             sum+=node->val;
//             if(node->left!=NULL){
//             q.push(node->left);
//         }
//         if(node->right!=NULL){
//             q.push(node->right);
//         }
//         }
//         if(node==NULL){
//             v.push_back(sum);
//             sum=0;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }
//     }

//     return v;
// }

// class Solution {
// public:
//     long long kthLargestLevelSum(TreeNode* root, int k) {
//          vector<long long>sumvec=levelOrderTraversal(root);
//          sort(sumvec.begin(),sumvec.end(),greater<long long>());
//          if(sumvec.size()<k) return -1;
//          else return sumvec[k-1];
        
         
//     }
// };


// priority queue se kth largest nikalna optmise kr skte h