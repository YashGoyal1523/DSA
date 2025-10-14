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

bool searchInBST(Node* root, int target) {
	//base case
	if(root == NULL) {
		return false;
	}


	// check current 
	if(root->data == target ) {
		return true;
	}

	// nhi toh 
	//left ya right dekho
	
	else {if(target > root->data) {
        // right jao
		bool rightAns = searchInBST(root->right, target);
		return rightAns;
	}
	else {
        // left jao
		bool leftAns = searchInBST(root->left, target);
		return leftAns;
	}
	}
}

int main()
{
    Node* root=new Node(50);
    root->left=new Node(40);
    root->left->left=new Node(20);
    root->left->left->left=new Node(10);
    root->left->left->right=new Node(30);
    root->right=new Node(60);

    int target=10;

   bool ans= searchInBST(root,target); // will return true or false if found or not

    if (ans)
    {
        cout<<"yes";
    }
    else cout<<"no";
return 0;
}