#include <iostream>
#include<stack>
using namespace std;

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




int main() {

  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);


  
  int element = 400;
  insertAtBottom(st,element);

 // printing from top
  while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
  }

  return 0;
}

// tc - n (n elements ke niche jaana, n baar call hora fn (fn ka o(1) hai))


