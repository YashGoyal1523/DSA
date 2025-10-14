#include <iostream>
#include<stack>
using namespace std;

// m1- stack ka top dusre stack m daalte jao

// m2 - stack top se pop krte jao(store krte hue) fir jab khaali hojaye toh toh stored walo ko  insert at bottom krte jao vaapis jaate hue



void insertAtBottom(stack<int> &st, int element) {
  //base case
  if(st.empty()) {
    st.push(element);
    return;
  }

  //1 case main solve karunga
  int temp = st.top();
  st.pop();

  //baaaki recursion
  insertAtBottom(st, element);

  //backTrack
  st.push(temp);
}

void reverseStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }

  //1 case main solve krega
  int temp = st.top();
  st.pop();
  //recursion
  reverseStack(st);
  //backtrack
  insertAtBottom(st,temp);
}



int main() {

  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);



  reverseStack(st);

// printing from top
   while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
  }
  return 0;
}

// tc - o(n^2) (n-1,n-2,....0 ke niche insert at bottom karna)