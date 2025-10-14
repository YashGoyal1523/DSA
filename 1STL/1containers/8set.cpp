#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;


int main() {

    //ordered_set
    set<int> st;  // store unique in ordered manner

    st.insert(10);
    st.insert(15);
    st.insert(8);
    st.insert(4);

    if(st.count(155) == 1) {
        cout << "Found";
    }
    if(st.count(155) == 0) {
        cout << "not found";
    }

    if(st.find(155) != st.end() ) {
        cout << "Found";
    }
    else {
        cout << "Not found";
    }

    st.erase(10);

    st.erase(st.begin(), st.end());
    cout << st.size() << endl;

    cout << st.size() << endl;
    st.clear();
    cout << st.size() << endl;

    if(st.empty()) {
        cout << "set is empty" << endl;
    }
    else {
        cout << "set is not empty" << endl;
    }


    //traverse
    set<int>::iterator it = st.begin();

    while(it != st.end() ) {
        cout << *it << " ";
        it++;
    }


    //multiset

    multiset<int>ms;  // store duplicates as well and in ordered manner

    ms.insert(1);
    ms.insert(1);
    ms.insert(2);

    // erase(1) krne pe saare 1 erase hojayege
    // erase using iterator mein specfic position erase hoga

    
    //unordered set

    unordered_set<int>us; // store unique in unordered manner



    return 0;
}