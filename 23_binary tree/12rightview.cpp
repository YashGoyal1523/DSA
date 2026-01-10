// same as left bas right left uper niche

#include<iostream>
#include<vector>
#include<queue>
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
                                                  
  return node;

}

void levelOrderTraversal(Node*node){
   queue<Node *> q;
    q.push(node);
    q.push(NULL);  
    

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {  
            if (!q.empty()) 
            {   
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


void rightView(Node* root, int level, vector<int>& v) {
  if(root == NULL) 
	return;

  if(level == v.size()) {
	//iska matlab right view ki node milgyi h , store karlo
	v.push_back(root->data);
  }
 
  rightView(root->right, level+1, v); 
  rightView(root->left, level+1, v);// note right phle and left baadme aayega
  
 return;
}
int main()
{
    Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
  levelOrderTraversal(root);

   cout<<endl;

  vector<int>v;
  int level=0;

  rightView(root,level,v);

  for (int i = 0; i < v.size(); i++)
  {
    cout<<v[i]<<endl;
  }
  
return 0;
}