// given a binary tree , return no of nodes

//dfs se tree mein traverse kro and count kro
void countnodes(TreeNode* root, int &count){

    if(root==NULL){
        return;
    }
    count++;
    countnodes(root->left,count);
    countnodes(root->right,count);

}

int NoOfNodes(TreeNode* root){
    int count=0;
    countnodes(root,count);
    return count;
}

// other method

//nodes=1(count of current node) + nodes(left subtree) + nodes(right subtree)

int countnodes(TreeNode* root){
   
    if(root==NULL){
        return 0;
    }
    
    int left=countnodes(root->left);
    int right=countnodes(root->right);

    int totalnodes=left+right+1;
    
    return totalnodes;

}

int NoOfNodes(TreeNode* root){
    
    int ans=countnodes(root);
    return return;
}
