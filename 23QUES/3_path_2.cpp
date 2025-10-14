// shortest path from any node to any other node 

// lc 2096 : Step-By-Step Directions From a Binary Tree Node to Another

// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// method-
// lowest common ancestor nikalo
// lca se source ka path lo 
// lca se dest ka path lo
// source wale path mein sbko U lelo
// dono path ko jod lo

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

// class Solution {
// public:

//     TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
//         if(root == NULL )
//         return NULL;
//         if(root->val == p) {
//              return root;
//         }
//         if(root->val == q) {
//             return root;
//         }
        
//         TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

//         if(leftAns == NULL && rightAns == NULL)
//             return NULL;
//         else if(leftAns != NULL && rightAns == NULL)
//             return leftAns;
//         else if(leftAns == NULL && rightAns != NULL)
//             return rightAns;
//         else 
//         return root;

//     }


// void findpath(TreeNode* node,int startValue,int destValue,string &temp,string &srcpath,string&destpath){    // temp ko by ref leliya as  MLE aara tha toh space bachani thi toh isse bachali

//     if(node==NULL) {
//         return ;
//     }
//     if(node->val==startValue){
//         srcpath=temp ;
//                           // yaha return nhi krege as kya pata src lca ho and fir destination isi direction m aage hogi toh return krne se yaha dikkat aayegi
//     }
//     if(node->val==destValue){
//         destpath=temp ;
//                          // yaha return nhi krege as kya pata dest lca ho and fir src isi direction m aage hogi toh return krne se yaha dikkat aayegi
//     }


//     temp.push_back('L');
//     findpath(node->left,startValue,destValue,temp,srcpath,destpath) ;
//     temp.pop_back();

//     temp.push_back('R');
//     findpath(node->right,startValue,destValue,temp,srcpath,destpath) ;
//     temp.pop_back();

//     return;
// }


//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         TreeNode *lca = lowestCommonAncestor(root,startValue,destValue);
//         string temp;
//         string srcpath;
//         string destpath;
//         findpath(lca,startValue,destValue,temp,srcpath,destpath);

//     for(auto &i: srcpath){
//         i='U';
//     }

//     return srcpath+destpath;
//     }
// };