// lc 160

//striver
// https://youtu.be/0DYoPz2Tpt4?si=oj0MkeOI8ENrkAih

//m1 bruteforce
//using two for loops
//for every node in listA check if that node is present in listB

node* intersectionPresent(node* head1,node* head2) {
    while(head1 != NULL) {
        node* temp = head2;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head1) return head1;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}



// m2 : map 
// A mein traverse krke sab mark krlege. fir B traverse krege koi marked mili toh yes vrna no

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *tempA=headA;
//         ListNode *tempB=headB;
//        map<ListNode*,int>m;
//         while(tempA!=NULL){
//             m[tempA]=1;
//             tempA=tempA->next;
//         }
//       while(tempB!=NULL){
//            if( m[tempB]==1) return tempB;
//             else tempB=tempB->next;
//         }
//         return NULL;
//     }
// };


// m3 : difference in length ko handle krke simultaneous traverse krke check
// dono ki length nikal lo
// dono ki same hai toh ....kuch nhi krna.... normally simultaneous traverse kro starting se and check krte jao
// badi choti h toh ....choti wale mein normally ptr start mein rkho  and badi wali mein ptr start se diff in length steps aage bhadado .......ab simultaeous traverse kro and check krte jao
class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        ListNode* A = headA;
        ListNode* B = headB;

        int diff = abs(lenA - lenB);

        if (lenA > lenB) {
            while (diff--)
                A = A->next;
        } else {
            while (diff--)
                B = B->next;
        }

        while (A && B) {
            if (A == B)
                return A;

            A = A->next;
            B = B->next;
        }

        return NULL;
    }
};

//m4 optimised
//Using the same concept of m3, a different approach can be implemented
//dono mein simultaneous traverse kro
// koi pointer null hojaye toh aage use uski list se dusre list ke starting m lagado and fir aage usme traverso kro
//krto rho jabtak dono collide nhi krte


class Solution {
public:
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
    ListNode* d2 = headB;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headB:d1->next;
        d2 = d2 == NULL? headA:d2->next;
    }
    
    return d1; // or d2
    }
};
