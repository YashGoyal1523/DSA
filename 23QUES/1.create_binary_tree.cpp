// lc 2196 Create Binary Tree From Descriptions

// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.


// ans link : https://youtu.be/Sg0hiTM85AI?si=QOCZbf8XIRRkQXGS




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution
// {
// public:
//     TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
//     {
//         unordered_map<int, TreeNode *> mp;  // will maintain present nodes ie nodes which have been created // <value of node, pointer to node>
//         unordered_map<int, bool> hasParent;  // will maintain whether node ka parent h ya nhi....yeh last m root node nikalne m help krega
//         for (auto description : descriptions)
//         {
//             int parentVal = description[0], childVal = description[1], isLeft = description[2];
//             TreeNode *parentNode = nullptr, *childNode = nullptr;
//             if (mp.find(parentVal) == mp.end()){   // agar is val ki node phle se present noi
//                 parentNode = new TreeNode(parentVal);    // toh nayi banado
//                 mp[parentVal] = parentNode; // map mein daal lo node ko
//             }
//             else {
//                 parentNode = mp[parentVal];   // agar node present h toh usko uthalo
//             }
//             if (mp.find(childVal) == mp.end()){   // agar is val ki node phle se present noi
//                 childNode = new TreeNode(childVal);  //toh nayi banado
//                  mp[childVal] = childNode; // map mein daal lo node ko
//             }
//             else{
//                 childNode = mp[childVal]; // agar node present h toh usko uthalo
//             }
//             if (isLeft){
//                 parentNode->left = childNode;  // left child h to left par lagado
//             }
//             else{
//                 parentNode->right = childNode;   // vrna right par lagado
//             }
//             hasParent[childVal] = true;   // child ka parent true krdo map m
 
//         }
//         // tree bangya
//          // ab root node nikal lete
//         TreeNode *rootNode = nullptr; 
//         for (auto i : mp)
//         {
//             if (!hasParent[i.first])    // jiska parent nhi vhi root node
//                 rootNode = i.second;
//         }
//         return rootNode;
//     }
// };



