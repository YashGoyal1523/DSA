#include <iostream>  // bfs traversal: level order     dfs traversals: preorder,inorder,postorder
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// it returns root node of the created tree
Node *createTree()
{
    cout << "enter the value for Node: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // Step1: create Node
    Node *node = new Node(data);
    // Step2: Create left subtree
    cout << "now left of Node: " << node->data << endl;
    node->left = createTree();
    // Step3: Create right subtree
    cout << " now right of Node: " << node->data << endl;
    node->right = createTree();
    return node;
}

// recursion sochne/yaad krne ka approach : phle root node access kro ie print kro , fir uske left mein jao (recursion se) ,fir uske right mein jao (recusrsion se)

 
void preOrderTraversal(Node *node)  // root node aara pass hoke
{
    // base case
    if (node == NULL)
    {
        return;
    }
    // N L R

    // N: current (ek case khud sambhalo)
    cout << node->data << " ";

    //(baaki recursion krdegaa)
    
    // L:left 
    preOrderTraversal(node->left);
    // R:right
    preOrderTraversal(node->right);
    return;
}
void inorderTraversal(Node *root)
{
    // LNR
    // base case
    if (root == NULL)
    {
        return;
    }
    // L
    inorderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inorderTraversal(root->right);

    return;
}

void postOrderTraversal(Node *node)
{
    // LRN
    // base case
    if (node == NULL)
    {
        return;
    }
    // L
    postOrderTraversal(node->left);
    // R
    postOrderTraversal(node->right);
    // N
    cout << node->data << " ";

    return;
}


//level order(bfs)
// left to right

// (printing in same line)

// void levelOrderTraversal(Node *node)
// {
//     queue<Node *> q;
//     q.push(node);
//     // asli traversal start krete h
//     while (!q.empty())
//     {
//         Node *front = q.front();
//         q.pop();
//         cout << front->data << " ";
//         if (front->left != NULL)
//         {
//             q.push(front->left);          // agar right to left print krte toh phle right wala krte fir left wala
//         }
//         if (front->right != NULL)
//         {
//             q.push(front->right);
//         }
//     }
// }

// (printing in different lines acc to level )

// using checkmark (we will see how to use checkmarks in queue....note: we are storing pointers in queue and we use null as checkmark in pointers....)

// here checkmark will determine level over 
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

        if (front != NULL)
        { 
            // valid node wala case 
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
        else
        {   
             // null milgya yaani  level khatm hogyaa... 
             //next line krooo....and checkmark push krdo next level ke liye (//   note level khatm hogya toh uss level ke sab traverse hoke print hogye  hogee and next level ke sab queue mein push hogye hoge (ie queue mein ab next level ke elements pade hai....ie queue ka front is next level ka first and aage saare stored hai level ke).....toh ab next level ke liye checkmark lagado yaani null push krdo firse )
         
            if (!q.empty()) // yeh check krlo kya pata khatm hi hogyaa ho tree ...q is empty yaani next line ka kuch push nhi hua toh khatm tree...  
            {   
                cout << endl;
                q.push(NULL);
                
            }      
        }
                                                   
    }
}
int main()
{
    Node *root = createTree(); // return the root node

    cout << "Printing Preorder: " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing Inorder: " << endl;
    inorderTraversal(root);
    cout << endl;

    cout << "Printing PostOrder: " << endl;
    postOrderTraversal(root);
    cout << endl;

    cout << "Level Order : " << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}





// tc : o(n) ;n : nodes,    sc:o(1):if recursive stack ignored and o(h); h : height if not ignored(recusive stack m max fn ..height jitne hoge at an instance).... of pre in post sc
// tc : o(n) , sc: o(x); x: nodes in level with max nodes..(queue mein max elements uss max level wale nodes jitne hoge at an instance)
