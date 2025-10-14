#include <iostream>     // bas base case mein change aajayega thoda sa in code comparing from code of finding middle element 
#include<stack>
using namespace std;

void delete_(stack<int> &st, int& pos) {
  //base case
  if(pos == 1) {
   st.pop();   // middle deleted
    
    return;
  }
  
  //1 case hum solve krenge
  pos--;
  int temp = st.top();
  st.pop();

  //recursion
  delete_(st,pos);

  //backtrack : vaapis stack bharne ke liye
  st.push(temp);
}

void deleteMiddleElement(stack<int> &st) {
  int size = st.size();
 
    int pos = 0;
    // odd no of elements
    if(size & 1) { 
      pos = size/2 + 1;
    }
    else {
      //even
      pos = size/2;
    }
    
    delete_(st,pos);
    return;
  }


int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  cout << "before size" << st.size() << endl; 
   deleteMiddleElement(st);
  

  cout << "after size" << st.size() << endl; 
  return 0;
}