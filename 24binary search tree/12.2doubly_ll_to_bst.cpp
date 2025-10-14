// convert given sorted doubly ll to bst 
// inplace needed


// ll is sorted so ll ka mid wala will be root node...mid se left will make left subtree and mid se right will make right subtree
//LNR se krege... isme RNL mein extra processing lagegi
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


Node* convertDLLtoBST(Node* &head, int n) {   // head by ref
	  
    //LNR se krege... isme RNL mein extra processing lagegi
    //LNR

    //base case
	if(head == NULL || n<=0) {
		return NULL;
	}

	//L
	Node* leftSubtree = convertDLLtoBST(head, n/2);

	//N 
	Node* root = head;
	root->left = leftSubtree;
	//head update
	head  = head->right;

	///R
	Node* rightSubtree = convertDLLtoBST(head, n-n/2-1);
	root->right = rightSubtree;

	return root;
	
}

void levelOrderTraversal(Node *node)
{
    queue<Node *> q;       
    q.push(node); 
    q.push(NULL);  

    
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        { 
            if (!q.empty()) {
                cout << endl;
                q.push(NULL);
                
            }
        }
        else
        {   
            cout << front->data <<" ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
                                                        
    }
}
int main() {

	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->left = NULL;
	first->right = second;
    second->left = first;
	second->right = third;
    third->left = second;
	third->right = NULL;

	
	Node* head = first;
    int n=3; // no of nodes

	Node* root = convertDLLtoBST(head, n);
	levelOrderTraversal(root);

	return 0;
}
