// print bottom view of given binary tree

// same topview jsa bas jaha humne map m kiya tha ki phle se dala hua tha toh dobara nhi dalna ..usme dobara daalte jao

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



void printBottomView(Node* root) {
	map<int,int> hdToNodemap;
	queue< pair<Node* , int> > q;
	q.push(make_pair(root, 0));

	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		//overwrite entries for hd in map so that the deeper nodes can be stored
		hdToNodemap[hd] = frontNode->data;

		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1)); 
		}

	}
	cout << "printing bottom view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}

}




int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
 
  
  printBottomView(root);



  return 0;
}