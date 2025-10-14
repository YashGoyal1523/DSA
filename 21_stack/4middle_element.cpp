#include <iostream>
#include<stack>
using namespace std;

 // we see if we number elements from top (1,2,3,....) then in case of even elements middle element is n/2 th(considering upper of the two middle as middle) and in case of odd its n/2+1 th
    

void middle(stack<int> &st, int& pos, int &ans) {
  //base case
  if(pos == 1) {
    ans =  st.top();
    
    return;
  }
  //1 case hum solve krenge
  pos--;
  int temp = st.top();
  st.pop();
  //recursion
  middle(st,pos,ans);
  //backtrack : vaapis stack bharne ke liye
  st.push(temp);
}

int getMiddleElement(stack<int> &st) {
  int size = st.size();
  if(st.empty()){
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else {
    //stack is not empty
    int pos = 0;
    // odd no of elements
    if(size & 1) { 
      pos = size/2 + 1;
    }
    else {
      //even
      pos = size/2;
    }
    int ans = -1;
    middle(st,pos,ans);
    return ans;
  }
}

int main() {
  stack<int> st;                
  st.push(10);
  st.push(20);
  st.push(30);                      
  st.push(50);
  st.push(60);

  
  int mid = getMiddleElement(st);
  cout << "Middle element: " << mid << endl;

  
  return 0;
}