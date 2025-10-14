// sorted from bottom to top order


#include <iostream>
#include<stack>
using namespace std;

// uper se check krte hue aao and position par insert krdo


void insertSorted(stack<int> &st, int element)
{
    // base case
    if (st.empty() || element > st.top())   // yeh empty wali condition miss mat krdenaaa.....it will work when initially only list is empty ya insert wala element sabse niche dalega
    {
        st.push(element);
        return;
        
    }
    // 1 case sambhalna h
    int temp = st.top();
    st.pop();
    // recursion sambhalega
    insertSorted(st, element);
    // backtrack
    st.push(temp);
}

int main()
{
    stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  insertSorted(st,0);
  // printing from top
  while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
  }

    return 0;
}