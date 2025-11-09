//find n/2th node

//m1 (two pass approach)        
// phle traverse krke total nodes count kro
// fir dobara start se n/2th node pe traverse kro and return that node

//m2 (one pass approach)
// slow and fast pointer approach
// maintain two pointers slow and fast both at head initially
// move fast pointer two steps and slow pointer one step at a time (jab fast 2 krlega tab slow 1 krega)
// when fast pointer reaches end , slow pointer will be at n/2th node

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

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move one step
        fast = fast->next->next;   // move two steps
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


// note : n/3th ke liye bhi same approach use kr skte h bas fast pointer ko 3 steps krwana hoga instead of 2 steps