// lc 876

// find middle node (agar do h toh aage wali)

// m1 (two pass approach)        
// phle traverse krke total nodes count kro
// fir dobara start se middle node pe traverse kro and return that node

// m2 (one pass approach)
// slow and fast pointer approach
// maintain two pointers slow and fast both at head initially
// jab fast 2 krlega tab slow 1 krega
// when fast pointer reaches end ie null, slow pointer will be at middle node (floor(n/2)+1th node) (1 based indexing)

#include <bits/stdc++.h>
using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to find the middle node
ListNode* findMiddle(ListNode* head) {
    if (!head) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

  
     while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                // main yaha keh skta hu k fast ne 2 step chal liye h
                // ab slow ko bhi chalwao ek step
                slow = slow->next;
            }
        }
    return slow; // slow now points to middle
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* mid = findMiddle(head);
    cout << "Middle node value: " << mid->val << endl;

    return 0;
}

//note: agar isi mein do middle nodes m piche wala lene hota toh fast wala jab last node pe hota tab uthalete slow ko ....so...dono jagah fast->next krlege

// note : n/3 (⌊n/3⌋ + 1 th node (1 based indexing)) ke liye bhi same approach use kr skte h bas fast pointer ko 3 steps krwana hoga instead of 2 steps....jab fast 3 steps krega tab slow 1 step krega....jab fast end pahunchega tab slow required pe pahuncha hoga
// n/k -> fast by k then slow by 1