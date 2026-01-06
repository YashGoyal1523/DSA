//lc 1161

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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int currsum=root->val;
        int currlvl=1;
        int anslvl=-1;
        int maxsum=-1e9;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node!=NULL){
                currsum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            else{
                if(currsum>maxsum){
                    maxsum=currsum;
                    anslvl=currlvl;
                }
                if(!q.empty()){
                    q.push(NULL);
                    currlvl++;
                    currsum=0;
                }
            }
        }
        return anslvl;
    }
};