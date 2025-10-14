
// linked nodes banani




// 1.manually creation and attachmnent of nodes
#include<iostream>  
using namespace std ;

class node{           
  public:
	int data;
	node* left;
	node* right;

    // para ctor
	node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

int main()
{

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<< root->right->right->data;
return 0;
}