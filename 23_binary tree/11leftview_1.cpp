
// har level ka first show hoga


// m1 using level order traversal

#include<iostream>  
#include<queue>
using namespace std ;

class Node{            
  public:
	int data;
	Node* left;
	Node* right;

    // para ctor
	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

void leftview(Node *node)
{      // level order travrsal use krege
// null milne par print krdege front element.. ...isse next level ka first miljayega...(null milne ke baad empty nhi honi chahie :)....note first level ka rehjayega par aise ...so first level ke liye shuru mein hi print krdege jab voh push krege

    queue<Node *> q;
    q.push(node);
    q.push(NULL);  // checkmark // shows level complete // root node ke baad toh pkka h level over isiliye daaldia

    cout<<q.front()->data<<endl;       // endl krdege for line change ...hence level wise hojayega

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        { // null milgya yaani  level khatm hogyaa... 
         //   note level khatm hogya toh uss level ke sab traverse hogye and next level ke sab push hogye hoge...toh ab queue mein front par next level ka first pada hoga toh.. q.front()-> data ...print krdo... usse next level ka first miljayegaa...and next level ke liye checkmark lagado yaani null push krdo firse 
            if (!q.empty()) // yeh check krlo kya pata khatm hi hogyaa ho tree ...q is empty yaani next line ka kuch push nhi hua toh khatm tree...  
            {   
                cout <<q.front()->data<<endl;
                q.push(NULL);
                
            }
        }
        else
        {
            // valid node wala case
            
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

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    leftview(root);
    
return 0;
}