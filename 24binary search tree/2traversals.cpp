// sab traversals code same as to binary tree only as ...ab hai toh yeh binary tree hi... bas creation style alag h...banne ke baad toh binary tree hi h at the end 

#include<iostream>
#include<queue>
using namespace std ;
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
int main()
{
    //[50,40,20,10,30,60]
    Node* root=new Node(50);
    root->left=new Node(40);
    root->left->left=new Node(20);
    root->left->left->left=new Node(10);
    root->left->left->right=new Node(30);
    root->right=new Node(60);

   cout << "Level Order : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    
return 0;
}



// inorder (LNR) of bst gives sorted order


// datatype and variable name cant be same