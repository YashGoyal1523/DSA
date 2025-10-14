// // leetcode 104

// //  height and max depth is same thing


// // m1 : recursion : sochne/yaad krne  ki approach -> find root node ke left ki height using recursion ,find right ki height using recursion , jo badi usme root node ka +1 krke height of tree milgya

// int maxDepth(TreeNode* root) {
// //base case
	// if(root == NULL ) {
	//     return 0;
	// }
   
	// int leftHeight = maxDepth(root->left);
	// int rightHeight = maxDepth(root->right);     // phle right m jaana baad m left m jaana bhi kr skte
	// int height = max(leftHeight, rightHeight) + 1;  // +1 for root node
	// return height;

// }


// // m2 : level order traversal (checkmark wala).... jab bhi null push krre ho toh count ++ krdo as null tab push krre jab ek level khatm hora ho

// int maxDepth(TreeNode* root) {

// // IMP Galti : kya pata tree hi na ho to check krlena phle
// if(root==NULL)
// 	return 0;


// queue<TreeNode*> q;
// int count=0;
// q.push(root);
// q.push(NULL);
// count++;

// //asli traversal start krete h 

// while(!q.empty()) {
// 	TreeNode* front = q.front();
// 	q.pop();

// 	if(front == NULL) {
// 		if(!q.empty()) {
// 			q.push(NULL);
//          count++;
// 		}
// 	}
// 	else {
// 		//valid node wala case

// 		if(front->left != NULL) {
// 			q.push(front->left);
// 		}
// 		if(front->right != NULL) {
// 			q.push(front->right);
// 		}
// 	}
// }

// return count;

// }