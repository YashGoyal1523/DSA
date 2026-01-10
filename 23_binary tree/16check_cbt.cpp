// lc 958


//non null node ke left mein null nhi honi chahie

class Solution {
public:

   bool levelOrderTraversal(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    bool nullfound=false;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();

        if(front==NULL){
            nullfound=true;
        }
        else{
            if(nullfound) return false;

            q.push(front->left);
            q.push(front->right);

        }
    }
    return true;
   }

    bool isCompleteTree(TreeNode* root) {
       bool ans= levelOrderTraversal(root);
        return ans;
    }
};
