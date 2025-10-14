// leetcode 236 lowest common ancestor

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL )
//         return NULL;
//         if(root->val == p->val) {  // root==p bhi dekh skte
//              return p;     // root bhi return kr skte
//         }
//         if(root->val == q->val) {
//             return q;
//         }
        
//         TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);   // phle right baad m left bhi kar skte 

//         if(leftAns == NULL && rightAns == NULL)
//             return NULL;
//         else if(leftAns != NULL && rightAns == NULL)
//             return leftAns;
//         else if(leftAns == NULL && rightAns != NULL)
//             return rightAns;
//         else //leftAns !=NULL && rightAns != NULL
//         return root;

//     }
// };



// note: isme dono ki nodes ka pointer diya h.....toh ...if condition mein chahe  value compare krlo ...chaho toh seedha pointer hi compare krlo ...and koi bhi pointer return krlo (root ya node wala)...and...agar unki value di hoti toh value hi compare krskte the and return root ka pointer krlete

// value di hoti

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
//         else //leftAns !=NULL && rightAns != NULL
//         return root;

//     }