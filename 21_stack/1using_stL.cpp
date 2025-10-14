#include<iostream>
#include<stack> // include krns pdega
using namespace std ;
int main()
{
    // creation
    stack<int>st;

    //insertion
    st.push(1);
    st.push(2);
    st.push(3);   // sabse niche 1 fir uper 3 fir uper 3

    // size
    cout<<st.size()<<endl;
     
    // remove
    st.pop(); // uper se remove hoga // 3 removed

    // check empty- st.empty() : returns true if yes ,false if no 
    if (st.empty()){   // or st.empty()==true  // if stack is empty 
        cout<<"empty"<<endl; 
    } 
    else cout<<"not empty"<<endl;

    // top element
    cout<<st.top()<<endl;
     
return 0;
}


// note: agar empty stack mein top access krege toh error dega toh jaha bhi top func use kro vaha dekhlena empty nhi honi chahie ...uski condition daaldena accordingly