
// sorted from bottom to top order



#include <iostream>
#include<stack>
using namespace std;



// niche tak aao pop krte hue and vaapis jaate hue insert sorted krte rho


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

void sortStack(stack<int> &st) {
//base case
if(st.empty()) {
return;
}
//1 case
int temp = st.top();
st.pop();
//recursion
sortStack(st);
//backtrack
insertSorted(st,temp);
}

int main()
{
    stack<int> st;
  st.push(5);
  st.push(4);
  st.push(3);
  st.push(2);
  st.push(1);

  sortStack(st);
  // printing from top
  while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
  }

    return 0;
}