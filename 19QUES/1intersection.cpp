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

int getDifference(ListNode* head1,ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else if 0 then barabar else if positive then list1 badi
}


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getDifference(headA,headB);
        if(diff < 0) { //list B badi h
            while(diff++ != 0) headB = headB->next; 
        }
        else if(diff>0) { // list A badi h
            while(diff-- != 0) headA = headA->next;
        }
        //ab dono heads se aage length barabar h
        //ab travser kro
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        //no intersection
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