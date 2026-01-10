// leetcode 110

// brute force

// recursion use krne k liye sochne ki approach: tree will be balanced if root node is balanced,uska left side is balanced(use recursion) , uska right side is balanced(use recursion)

// proper sochne ka tarika : har node pe validate krre

// int height(TreeNode* root) {
// 	//base case
// 	if(root == NULL ) {
// 		return 0;
// 	}
// 	int leftHeight = height(root->left);
// 	int rightHeight = height(root->right);
// 	int heightt = max(leftHeight, rightHeight) + 1;
// 	return heightt;
// }
//     bool isBalanced(TreeNode* root) {
//         //base case
//         if(root==NULL){
//             return true;
//         }
//         //curr node solve
//         int leftHeight=height(root->left);
//         int rightHeight=height(root->right);

//         int diff=abs(leftHeight-rightHeight);

//         bool currNodeAns=(diff<=1);  // will store ans of whether diff is less than equal to 1 or not.if yes then true ,if not then false // is similar to  if(diff<=1){ bool currNodeAns=true;} else{ bool currNodeAns=false;}

//         bool leftAns=isBalanced(root->left);
//         bool rightAns=isBalanced(root->right);

//         if(currNodeAns&&leftAns&&rightAns){
//             return true;
//         }
//         else {
// return false;
// }
//     }