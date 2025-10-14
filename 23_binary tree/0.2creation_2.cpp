// 2.using recursion
#include<iostream>
using namespace std ;           

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

//it returns root node of the created tree
Node* createTree() {

  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

//base case
  if(data == -1) {
	return NULL;
  }

  //Step1: create Node
  Node* node = new Node(data);

  //Step2: Create left subtree
  cout << "tell left of Node: " << node->data << endl;
  node->left = createTree();

  //Step3: Create right subtree
  cout << " tell right of Node: " << node->data << endl;
  node->right = createTree();
                                                    // note : this.... first makes current node then its left node then its right node....
  return node;

}
int main()
{
    Node* root=createTree();     // root node return kro
return 0;
}


// tips
// trees ke ques mein mostly recursion ka ek hi pattern lagega...remember ek case khud solve kro root node ka... baaki left right ko recursion krdegaa
// jsa yaha kiya ...root node banao fir uska left and right subtree banadega recursion
// rememeber jaha bhi left , right se related kuch krna  aayega vaha recursion lagado...(ho skta h root case ko solve krne m left right ka use ho toh ..toh left right k liye recursion lagadenaa bas)
// base case mostly mein aayega agar root node null ho toh kya hoga....kyuki hume last tak jaate ,most ques m(it will also cater when tree is empty case)