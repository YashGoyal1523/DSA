// lc 98

// for a node
// if node lies in valid range
// valid range- for a node: [lowerbound ,upperbound] (root node -> [intmin,intmax] ...given node value lies in [intmin,intmax]), for its children : if its left child then [lowerbound, node) , if its right child then (node ,uperbound] 
// node ka left subtree is bst 
// node ka right subtree is bst 
// node se bst h

// validate bst


class Solution
{
public:
    bool solve(TreeNode *root, long long int lowerbound, long long int upperbound)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }
        bool cond= root->val > lowerbound&& root->val<upperbound;
        bool leftAns = solve(root->left, lowerbound, root->val);
        bool rightAns = solve(root->right, root->val, upperbound);
        if (cond&&leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        long long int lowerbound = -2147483649;   // int min se chota lelo
        long long int upperbound = 2147483648; // int max se bada lelo 
        bool ans = solve(root, lowerbound, upperbound);
        return ans;
    }
};
