// smjhna baaki hai ache se


// LC 1110 Delete Nodes And Return Forest

// Given the root of a binary tree, each node in the tree has a distinct value.
// After deleting all nodes with a value in array to_delete, we are left with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. You may return the result in any order.


// ans link : https://youtu.be/FQ7HuXTM-KA?si=oH5JyMJXJXf-UEis

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
// class Solution
// {
// public:
//     void dfsPre(TreeNode *root, unordered_set<int> &s, vector<TreeNode *> &ans, bool is_root)
//     {
//         if (root == nullptr)
//             return;

//         if (s.find(root->val) != s.end()) // mtlb remove hoga
//         {
//             dfsPre(root->left, s, ans, true);   //  child roots banenge
//             dfsPre(root->right, s, ans, true);
//         }
//         else              //remove nhi hora
//         {
//             if (is_root)         // root h toh push
//                 ans.push_back(root);

//             TreeNode *leftNode = root->left;      // ab uske left right dekho
//             TreeNode *rightNode = root->right;
           
//                 if (root->left!=NULL && s.find(root->left->val) != s.end()) // remove wali list m h left walla // yeh null wala check krlia as agar null ho toh yeh error dedega fir uski val check krna
//                     root->left = nullptr;  // parent se hatao
            
            
//                 if (root->right!=NULL && s.find(root->right->val) != s.end()) // remove wali m h right wala
//                     root->right = nullptr;  // parent se hatao
            
            
//             dfsPre(leftNode, s, ans, false);    // left m jao
//             dfsPre(rightNode, s, ans, false);   // right m jao
//         }
//     }
//     vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
//     {
//         vector<TreeNode *> ans;
//         unordered_set<int> s(to_delete.begin(), to_delete.end());   // isme se find fn se dekhte rhege current node delete krni ya nhi.....mmap bhi use kr skte
//         dfsPre(root, s, ans, true);
//         return ans;
//     }
// };