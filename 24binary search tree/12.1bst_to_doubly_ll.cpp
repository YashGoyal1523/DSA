// Convert given bst to a Sorted doubly linked list

// The task is to convert a Binary Search Tree (BST) into a sorted Doubly-Linked List, utilizing an in-place transformation
// The conversion should maintain the following conditions:
// Each node's left pointer should reference its predecessor in the list.
// Each node's right pointer should reference its successor in the list.
// The resultant structure needs to be returned with a pointer to its smallest element, effectively the head of the list.



//LNR se kr skte par usme extra processing lagegi.... RNL traversal se kro ...ez rhega
#include <iostream>
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


void convertBSTtoDLL(Node* root, Node* &head) {   // head by ref
	//LNR se kr skte par usme extra processing lagegi.... RNL traversal se kro ...ez rhega
    //  RNL

	if(root == NULL ) {
		return;
	}

	//R
	convertBSTtoDLL(root->right, head);

	//N
	//attaching next pointer of current node to head of LL
	root->right = head;
	//attaching prev pointer of head of LL to current node
	if(head != NULL)
		head ->left = root;
	//head update
	head = root;

	//L
	convertBSTtoDLL(root->left, head);

    return; 
}


void printLinkedList(Node* head) {
	Node* temp = head;
	cout << "printing the entire list: " << endl;
	while(temp != NULL) {
		cout << temp->data;
		temp = temp->right;
        if(temp!=NULL){
            cout<<"<->";
        }
	}
	cout << endl;
}

int main() {

	Node* first = new Node(20);
	Node* second = new Node(10);
	Node* third = new Node(30);

	first->left = second;
	first->right = third;

	Node* h = first;

	Node* head = NULL;

    convertBSTtoDLL(h, head);
    printLinkedList(head);

	return 0;
}
