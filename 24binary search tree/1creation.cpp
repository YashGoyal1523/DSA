
// bst - Left subtree < Node < Right subtree


// manually toh kar hi sktee....data ke acc nodes attach krte jao

// recursion se dekho

#include <iostream>
#include<queue>
using namespace std;

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

Node* insertIntoBST(Node* root, int data) {
	 // its first node 
	if(root == NULL) {
		root = new Node(data);
		return root;
	}

	//its not the first node
	if(data > root->data) {
		root->right = insertIntoBST( root->right, data);
	}
	else {
		root->left = insertIntoBST( root->left, data);
	}
	return root;
}

void createBST(Node* &root) {     // by ref
	cout << "Enter data:" << endl;
	int data;
	cin >> data;

	while(data != -1) {
		root = insertIntoBST(root, data);   // will return root after inserting the node
		cout << "Enter data:" << endl;
		cin >> data;
	}
}



int main() {

	Node* root = NULL;
	createBST(root);

	
 

	return 0;
}



// tc of insertion : skew bst -> o(n) , perfect bst -> o(logn)   n no of nodes