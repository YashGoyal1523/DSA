#include<iostream>
using namespace std ;
class Node{
	public:
	int data;
	Node* left;
	Node* right;

	Node(int value) {
		this->data = value;
		this->left = NULL;
		this->right = NULL;
	}
};

Node* minimum(Node*root){
    // no elements
    if(root==NULL){
        cout<<"no element"<<endl;
        return NULL;
    }
    
    // elements present hai
    // traverse to leftmost node
    Node* temp= root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    

    return temp;
}
int main()
{
    Node* root=new Node(50);
    root->left=new Node(40);
    root->left->left=new Node(20);
    root->left->left->left=new Node(10);
    root->left->left->right=new Node(30);
    root->right=new Node(60);

    Node* minNode=minimum(root);  // will return node of min value

    if(minNode==NULL){
        cout<<"no elements so no min value";
    }
    else{
        cout<<"min value is " <<minNode->data;
    }
return 0;
}

// similar for max value....traverse to rightmost

// tc: o(height)