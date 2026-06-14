//kabhi hume linked list mein piche se aage travserse krna ho
//m1: reverse linked list bana ke usko traverse kar sakte hai
//m2: recursion se shuru se traverse krdo...jab backtrack hoga tab piche se aage wala miljayega

//lc 2130

//ek pointer starting m rkho
//dusre pointer ko half pe lejaake recursion se traverse krwado...
//jab recursion waa backtrack krra hoga tab usse and first pointer se dekhte jao

class Solution {

public:

void solve(ListNode* &start,ListNode* half,int &ans){
    if(half==NULL) return;

    //traverse
    solve(start,half->next,ans);

    //backtrack
    int val=start->val+half->val;

    ans=max(ans,val);

    start=start->next;

    return ;

}


    int pairSum(ListNode* head) {
        ListNode* half=head;
        ListNode* temp=head;

        while(temp!=NULL){
            temp=temp->next;
            if(temp!=NULL){
                half=half->next;
                temp=temp->next;
            }
        }

        ListNode* start=head;

        int ans=0;

        solve(start,half,ans);

        return ans;

    }
};