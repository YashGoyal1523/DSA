// leetcode 543

// bruteforce 
// approach: ya toh starting ending nodes dono root ke left hogi,ya dono right,ya ek left ek right
// so left case recursion se lo, right case recursion se lo , left right recursion se lo

//proper sochne ka tarika : har node pe dekhre ki ..agar usko turning pt maane path ka toh usse max kya hoga....sabka max lelo


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

// int diameterOfBinaryTree(TreeNode* root) {
// 	//base case
// 	if(root == NULL) {
// 		return 0;
// 	}   
// 	int option1 = diameterOfBinaryTree(root->left);
// 	int option2 = diameterOfBinaryTree(root->right);
// 	int option3 = height(root->left) + height(root->right);
// 	int diameter = max(option1, max(option2, option3));
// 	return diameter;
// }

// max func at a time do ke liye kaam krta isiliye teen ke liye phle do ka leliya fir unka teesre ke saath leliya

// tc : quadratic ( height fn baar baar call hora : n+n-1+n-2+.....+1 ... )