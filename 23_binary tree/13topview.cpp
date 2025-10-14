// print top view of given binary tree


// root node wale ko zero lvl lelo (vertical), left side wale -1,-2,....lvl lelo , right side wale 1,2,... lvl lelo...har level ke phla wala ie sbse uper wala print

 // level order traversal use krege


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



void printTopView(Node* root) {
     // level order traversal use krege

	map<int,int> hdToNodemap; //ordered map // maintains horizontal distance of a node from root node  (ie level of node)
	queue< pair<Node* , int> > q; // <node,hd>
    //initial state push
	q.push(make_pair(root, 0));

	while(!q.empty()) {
		pair<Node* ,int> temp = q.front();
		q.pop();

		Node* frontNode = temp.first;
		int hd = temp.second;

		//if there is no entry for hd in map, then create a new entry
		if(hdToNodemap.find(hd) == hdToNodemap.end()) {
			hdToNodemap[hd] = frontNode->data;
		}

		//child ko dekhna h 
		if(frontNode->left != NULL) {
			q.push(make_pair(frontNode->left, hd-1));
		}
		if(frontNode->right != NULL) {
			q.push(make_pair(frontNode->right, hd+1));
		}
		
	}
	cout << "printing top view: " << endl;
	for(auto i: hdToNodemap) {
		cout << i.second << " ";
	}
	
}


int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 


  printTopView(root);


	

  return 0;
}