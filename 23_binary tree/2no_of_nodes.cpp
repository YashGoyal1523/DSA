// given a binary tree , return no of nodes

void countnodes(TreeNode* root, int &count){
    // pre,in,post koi bhi use kr skte
    // pre se krte
    if(root==NULL){
        return;
    }
    count++;
    countnodes(root->left);
    countnodes(root->right);

}

int NoOfNodes(TreeNode* root){
    int count=0;
    countnodes(root,count);
    return count;
}