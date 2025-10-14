
// kth ancestor of a node in a binary tree

// https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1


Node* solve(Node*root, int&k, int node, int&ans){
if(!root) return NULL;
if(root->data == node) return root;

if(ans!=-1) return root; // optimisation

Node* left = solve(root->left, k, node, ans);
Node* right = solve(root->right, k, node, ans);


if(!left && !right) return NULL;

// mil chuki h child node
k--;
if(k == 0){
ans = root->data; 
}


if(left && !right) return left;

else if(!left && right) return right;

else return root;

}


int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
   Node* a= solve(root,k,node,ans);
    return ans;
}