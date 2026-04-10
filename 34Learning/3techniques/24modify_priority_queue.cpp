✅ SCENARIO 1: Get top elements WITHOUT changing original PQ
🟢 Method 1: Pop → Store → Reinsert

👉 Idea:

Remove top elements
Store them
Put them back
#include <bits/stdc++.h>
using namespace std;

void method1() {
    priority_queue<int> pq;
    pq.push(10); pq.push(30); pq.push(20); pq.push(5);

    vector<int> temp;
    vector<int> ans;

    int k = 2;

    // extract top k
    for(int i = 0; i < k && !pq.empty(); i++) {
        int x = pq.top();
        pq.pop();
        ans.push_back(x);
        temp.push_back(x);
    }

    // reinsert
    for(int x : temp) pq.push(x);

    // print answer
    for(int x : ans) cout << x << " ";
}
⏱️ Complexity:
O(k log n)
🟢 Method 2: Copy PQ

👉 Idea:

Copy pq
Work on copy
void method2() {
    priority_queue<int> pq;
    pq.push(10); pq.push(30); pq.push(20); pq.push(5);

    priority_queue<int> copy = pq;  // O(n)

    vector<int> ans;
    int k = 2;

    while(k-- && !copy.empty()) {
        ans.push_back(copy.top());
        copy.pop();
    }

    for(int x : ans) cout << x << " ";
}
⏱️ Complexity:
Copy: O(n)
Extract: O(k log n)
Total: O(n + k log n)




✅ SCENARIO 2: Remove specific elements from PQ
🟢 Method 1: Use vector and rebuild

👉 Idea:

Dump all elements
Keep only required ones
Rebuild pq
void remove_using_vector() {
    priority_queue<int> pq;
    pq.push(10); pq.push(30); pq.push(20); pq.push(5);

    vector<int> temp;

    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        if(x != 20) temp.push_back(x);  // remove 20
    }

    // rebuild pq
    for(int x : temp) pq.push(x);

    // print
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
🟢 Method 2: Use another PQ

👉 Idea:

Filter directly into new pq
void remove_using_new_pq() {
    priority_queue<int> pq;
    pq.push(10); pq.push(30); pq.push(20); pq.push(5);

    priority_queue<int> newpq;

    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        if(x != 20) newpq.push(x);
    }

    // copy back
    pq = newpq;

    // print
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}
⏱️ Complexity (both methods)
O(n log n)


//lc 355 dekho