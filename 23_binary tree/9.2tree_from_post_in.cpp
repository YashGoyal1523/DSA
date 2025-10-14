// create binary tree from given its inorder and postorder traversal

// postorder ka rightmost(say x) root hoga
// inorder mein x se left wale ..left subtree banayege and right wale...right subtree



#include<iostream>
#include<queue>
#include<map>
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


void levelOrderTraversal(Node *node)
{
    queue<Node *> q;       // will store addresses of nodes
    q.push(node); 
    q.push(NULL);  // checkmark // shows level complete / root node ke baad toh pkka h level over isiliye daaldia

    // asli traversal start krete h

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        { // null milgya yaani  level khatm hogyaa... next line krooo....
         //   note level khatm hogya toh uss level ke sab traverse hoke print hogye  hogee and next level ke sab queue mein push hogye hoge (ie queue mein ab next level ke elements pade hai...(pichla front element jisko investigate krre voh pop kr chuke hai)...ie queue ka front is next level ka first and aage saare stored hai level ke).....toh ab next level ke liye checkmark lagado yaani null push krdo firse 
            if (!q.empty()) // yeh check krlo kya pata khatm hi hogyaa ho tree ...q is empty yaani next line ka kuch push nhi hua toh khatm tree...  
            {   
                cout << endl;
                q.push(NULL);
                
            }                           // note agar yeh cout endl first  second if ke bich m likhege toh kuch farak nhi padega bass last mein print hoke next line m jaake end hogaa...abhi usi line m end hora 
        }
        else
        {   // null nhi mila
            // valid node wala case 
            // abhi level khatm nhi hua 
            // jaancha hua element print kro and uske left right push krdo
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
                                                        // note investigate wale element ko pop krke investigste krree...agar bina krre krtee tohh q.front()->data se jaachte and pop aise krte...if wale mein dono if ke bich m ...and else wale mein cases ke end mein
    }
}

void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap) {
for(int i=0; i<size; i++) {
int element = inorder[i];
int index = i;
valueToIndexMap[element] = index;
}
}


Node* constructTreeFromPostAndInorderTraversal(map<int,int> valueToIndexMap,int postOrder[], int inOrder[], int &postIndex, int inOrderStart, int inOrderEnd, int size) { // postIndex by ref krna hoga 
//base case
if (postIndex < 0 || inOrderStart > inOrderEnd) {
return NULL;
}

//1 case main solve krta hu 
int element = postOrder[postIndex];
postIndex-- ;
Node* root = new Node(element);

//element search krna padega inorder me
int position = valueToIndexMap[element];

//baaaki recursion sambhal lega
// phle right fir left 
root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder, inOrder, postIndex, position+1, inOrderEnd, size);
root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postOrder, inOrder, postIndex, inOrderStart, position-1, size);

return root;
}

 
int main() {
int inorder[] = {8,14,6,2,10,4};
int postorder[] = {8,6,14,4,10,2};
int size = 6;
int postOrderIndex = size-1; 
int inorderStart = 0;
int inorderEnd = size-1;
map<int,int> valueToIndexMap;
createMapping(inorder, size, valueToIndexMap);
Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postorder, inorder,postOrderIndex, inorderStart, inorderEnd, size);
cout << "Printing the entire tree: "<< endl;
levelOrderTraversal(root);
return 0;
}

