// lc 235 lca of bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL) {
            return NULL;
        }

        //case 1: p and q both comes in left subtree of root node
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p,q);
            return leftAns;
        }
        //case 2: p and q both comes in right subtree of root node
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        //case 3:
        //p is in left subtree of root node && q is on right subtree of root node
        // case 4:
        // q is in left subtree of root node && p is on right subtree of root node
        // case 5:
        // p is root node q is kuch bhi aur 
        // case 6:
        // q is root node p is kuch bhi aur
        // inme root node is only the lca
        return root;
    }
};