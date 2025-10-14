// given a complete binary tree(cbt) , check whether its a max heap or not
        
        // for a node
        // node > left child
        // node > right child
        // node ka left subtree heap h
        // node ka right subtree heap h
        // iss node se heap hai 


bool check(node* root) {
    if (root == NULL) {
        return true;
    }

    bool cond1 = true;
    if (root->left != NULL && root->left->data > root->data) {
        cond1 = false;
    }

    bool cond2 = true;
   
    if (root->right != NULL && root->right->data > root->data) {
        cond2 = false;
    }

    bool leftans = check(root->left);
    bool rightans = check(root->right);

    return cond1 && cond2 && leftans && rightans;
}