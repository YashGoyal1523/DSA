// given a complete binary search tree (complete binary tree + binary search tree) , convert it to max heap

// cbt toh hai hi bas heap property satisfy krni toh bas nodes ki value replace krni
// phle inorder store krlo vector m- ascending order milgya
// ab 2 tarike
//m1 ab vector ki starting se post order se tree nodes ko value dedo
//m2 vector ki ending se lvl order se tree nodes ko value dedo

// m1 se krte


void storeInorderTraversal(Node* root, vector<int>& in) {
if(root == NULL) {
return;
}
//LNR
storeInorderTraversal(root->left, in);
in.push_back(root->data);
storeInorderTraversal(root->right, in);
}

void replaceUsingPostOrder(Node* root, vector<int> in,int &index) {
if(root == NULL) {
return;
}
//LRN
replaceUsingPostOrder(root->left, in,index); 
replaceUsingPostOrder(root->right, in,index);
root->data = in[index];
index++ ;
}

Node* convertBSTIntoMaxHeap (Node* root) {
// store inorder
vector<int> inorder;
storeInorderTraversal(root, inorder);
//replace the node values with the sorted inorder values, using the postorder traversal
int index=0;
replaceUsingPostOrder(root, inorder,index);
return root;
}
