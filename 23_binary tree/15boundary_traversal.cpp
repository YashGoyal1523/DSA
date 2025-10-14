// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right bounda



#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;


	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}

void printLeftBoundary(Node* root) {
    //base case
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}

	cout << root->data << " ";
	if(root->left != NULL) {
		printLeftBoundary(root->left);
	}
	else {
		printLeftBoundary(root->right);
	}

    return;
}

void printRightBoundary(Node* root) {
    // base case
	if(root == NULL) {
		return;
	}
	if(root->left == NULL && root->right == NULL) {
		return;
	}
	

	if(root->right != NULL) {
			printRightBoundary(root->right);
	}
	else {
			printRightBoundary(root->left);
	}
	cout << root->data << " ";

    return;
}

void printLeafBoundary(Node* root) {
    //pre order se krre

	if(root == NULL )
		return;


	if(root->left == NULL && root->right == NULL) {
		cout << root->data <<" ";
	}
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
}


void boundaryTraversal(Node* root ) {
	if(root == NULL)
		return;

    // printLeftBoundary(root);
	// printLeafBoundary(root);
	// printRightBoundary(root);

// isme main root do baar print hojayega....left right wale mein.....single node case m  teen baar hojayegi ...left right leaf se



	// printLeftBoundary(root);
	// printLeafBoundary(root);
    // if(root->right!=NULL)
	// printRightBoundary(root->right);
    // else
	// printRightBoundary(root->left);

    // left right toh handled...par isme agar tree m ek hi node h toh voh do baar hojayega...left wale se and leaf wale se
    

    cout << root->data << " ";
	printLeftBoundary(root->left);
	printLeafBoundary(root);
	printRightBoundary(root->right);

  // left right toh handled...par isme agar tree m ek hi node h toh voh do baar hojayega...cout wale se and leaf wale se
    

	cout << root->data << " ";
	printLeftBoundary(root->left);
	printLeafBoundary(root->left);
	printLeafBoundary(root->right);
	printRightBoundary(root->right);
    // sab handled
}

int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 

  boundaryTraversal(root);
  

  return 0;
}