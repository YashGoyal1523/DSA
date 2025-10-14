// lc 653 two sum 4

// bruteforce-saare elements ek array m daalke nested loops se check krlo

// optimised- inorder traversal se elements ka sorted order store krlo ek array mein fir normal two pointer se nikal lo : o(n)
class Solution {
public:
    void storeInorder(TreeNode* root, vector<int> &inorder) {
        //base case
        if(root == NULL) {
            return;
        }
        //LNR
        storeInorder(root->left, inorder);
        //N
        inorder.push_back(root->val);
        //R
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root, inorder);

        //find target using 2 pointer approach
        int start = 0;
        int end = inorder.size()-1;

        while(start < end) {
            int sum = inorder[start] + inorder[end];
            if(sum == k) {
                return true;
            }
            else if(sum > k) {
                end--;
            }
            else if(sum < k) {
                start++;
            }
        }
        return false;
    }
};