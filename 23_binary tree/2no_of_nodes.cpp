// given a binary tree , return no of nodes

//rec dfs se tree mein traverse kro and count kro

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

// other tarika 

int countnodes(TreeNode* root){
   
    if(root==NULL){
        return 0;
    }

    int cnt=1; // for current node
    int left=countnodes(root->left);
    int right=countnodes(root->right);

    cnt+=left+right;
    
    return cnt;

}

int NoOfNodes(TreeNode* root){
    
    int ans=countnodes(root);
    return ans;
}
//iss recursion ko sochne ka proper way is dfs se traverse krna and count krna par dusra sochne ka way
//nodes=1(root node) + nodes(left subtree) + nodes(right subtree)
