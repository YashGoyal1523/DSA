// lc 2181
//  Merge Nodes in Between Zeros

// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Return the head of the modified linked list.

// The number of nodes in the list is in the range [3, 2 * 105].
// 0 <= Node.val <= 1000
// There are no two consecutive nodes with Node.val == 0.
// The beginning and end of the linked list have Node.val == 0.

// method1 (new list m ans banana)
//  given list mein second node se shuru hoke (first zero hi h) traverse krte jao and sum lete jao ....zero milte hi node banaloo sum value ki  and fir aage firse traverse krte jao...firse sum nikalo and zero milte hi daalte jao ...last wali zero ke baad rukjao

// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode* temp = head->next;
//         ListNode* dummy = new ListNode(); // dummy variable
//         ListNode* h = dummy;
//         int sum = 0;

//         while (temp != nullptr) {
//             if (temp->val == 0) {
//                 ListNode* node = new ListNode(sum);
//                 h->next=node;
//                 h=node;

//                 sum = 0;
//             } else {
//                 sum += temp->val;
//             }
//             temp = temp->next;
//         }
//          h=dummy->next;
//          delete dummy;
//          return h;
//     }
// };

// method 2 (usi list ko modify krna)
// lakshay bhaiya

// class Solution
// {
// public:
//     ListNode *mergeNodes(ListNode *head)
//     {

//         ListNode *temp1 = head;
//         ListNode *temp2 = head->next;
//         ListNode *LastNode = NULL;
//         int sum = 0;
//         while (temp2 != NULL)
//         {
//             if (temp2->val != 0)
//             {
//                 sum += temp2->val;
//             }
//             else
//             {
//                 // temp2->val == 0
//                 temp1->val = sum;
//                 LastNode = temp1;
//                 temp1 = temp1->next;
//                 sum = 0;
//             }
//             temp2 = temp2->next;
//         }

//         // req and non req list ko separate krlete
//         ListNode *temp = LastNode->next;
//         LastNode->next = NULL;
//         // Deleting non req List.
//         while (temp != NULL)
//         {
//             ListNode *nxt = temp->next;
//             delete temp;
//             temp = nxt;
//         }
//         return head;
//     }
// };