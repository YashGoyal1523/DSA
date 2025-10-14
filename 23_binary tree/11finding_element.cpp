// find whether a particular element is present or not

// we can use any mode of traversal to find

// lets do using preorder
#include <iostream>
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

  // base case
  if (data == -1)
  {
    return NULL;
  }

  // Step1: create Node
  Node *node = new Node(data);

  // Step2: Create left subtree
  cout << "tell left of Node: " << node->data << endl;
  node->left = createTree();

  // Step3: Create right subtree
  cout << " tell right of Node: " << node->data << endl;
  node->right = createTree();

  return node;
}

// //m1
// bool find(Node* node,int target){
//  // base case
//     if (node == NULL)
//     {
//         return false;
//     }

//     // N-current node check kroo
//     if (node->data==target)
//     {
//         return true;
//     }
//   // voh nhi h toh left right check kri
//     // L -  left wala check kro

//     bool leftans=find(node->left,target);

//     // R - right wala check kro
//     bool rightans=find(node->right,target);

//     return leftans||rightans;
// }

// m2 : better
bool find(Node *node, int target)
{
  // base case
  if (node == NULL)
  {
    return false;
  }

  // N-current node check kroo
  if (node->data == target)
  {
    return true;
  }
  // current nhi h toh
else{
  // L -  left wala check kro
  bool leftans = find(node->left, target);
  if (leftans == true)
  {
    return true;
  }
  // voh bhi nhi h toh
else{
  // R - right wala check kro
  bool rightans = find(node->right, target);
  // usi ka ans is final ans
  return rightans;
}
}
}
// m1 mein left right dono traverse hoge hi hoge.....m2 mein left hoga ... agar usme nhi mila toh hi right hogaa vrna noii

int main()
{
  Node *root = createTree();
  int target;
  cout << "enter target" << endl;
  cin >> target;

  bool present = find(root, target);

  if (present)
  {
    cout << "yes";
  }
  else
    cout << "no";
  return 0;
}
