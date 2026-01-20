// do stable descending sort ie largest to smallest and if two equal then smaller index first

//m1 using sort() function with custom comparator
//store value along with index then sort
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first) return a.second<b.second; //if values equal then smaller index first
    return a.first>b.first; //desc order
}
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n); // {value,index}
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr[i] = {val, i};
    }

    sort(arr.begin(), arr.end(), cmp);

    for (const auto &p : arr) {
        cout << p.first << " ";
    }
    cout << "\n";

    return 0;
}

//m2 using stable_sort() function

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first;   // descending by first
}

int main() {
    vector<pair<int,int>> v;

    stable_sort(v.begin(), v.end(), cmp);
}