// given inorder of a balanced bst ...create bst
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


void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";
			if(temp->left != NULL) {
				q.push(temp->left);
			}
			if(temp->right != NULL) {
				q.push(temp->right);
			}
		}
	}
}



Node* bstFromInorder(int inorder[], int s, int e) {
	//base case
	if(s > e) {
		return NULL;
	}

	//1 case solve krna h ....root khud banado
	int mid = (s+e)/2;
	int element  = inorder[mid];
	Node* root = new Node(element);         // balanced hai so mid wala will be root node

	//baaaaki recursion banadega left right ka
	root->left = bstFromInorder(inorder, s, mid-1);
	root->right = bstFromInorder(inorder, mid+1, e);

	return root;
}


int main() {

	int inorder[] = {10,20,30,40,50,60,70};
	int size = 7;
	int start = 0;
	int end = size-1;
	Node* root = bstFromInorder(inorder, start, end);

	levelOrderTraversal(root);

	



	return 0;
}